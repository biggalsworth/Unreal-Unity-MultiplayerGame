
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Diagnostics;
using System.Numerics;
using System.Collections;
using System.Threading;
using System.Collections.Concurrent;
using System.Threading.Tasks;

namespace MultiplayerServer
{
    public class Client
    {
        public Client(EndPoint r, int ID, Socket sock, int Team = 0, string Username = "Player")
        {
            health = 100;
            remote = r;
            id = ID;
            socket = sock;
            team = Team;

            if(Username != "Player")
                name = Username;
            else
                name = Username + ID.ToString();

            connected = true;

            LastSent = DateTime.Now.TimeOfDay;

            Position = Vector3.Zero;
            Rotation = Vector3.Zero;
        }
        public int health;
        public int team;
        public bool connected;
        public int kills;
        public int deaths;
        public int Weapon;

        public TimeSpan LastSent;

        //anything internal wont be changed
        internal int id;
        internal string name;
        internal EndPoint remote;
        internal Socket socket;

        public Vector3 SpawnPosition;
        public Vector3 Position;
        public Vector3 Rotation;


        public string PosString()
        {
            return (Position.X.ToString() + "\n" + Position.Y.ToString() + "\n" + Position.Z.ToString());
        }
        
        public string RotString()
        {
            return (Rotation.X.ToString() + "\n" + Rotation.Y.ToString() + "\n" + Rotation.Z.ToString());
        }

    }

    public struct Packet
    {
        public Packet(EndPoint r, string m) 
        { 
            remote = r; 
            message = m; 
        }

        public EndPoint remote;
        public string message;
    }

    public struct Flag
    {
        public int team;
        public bool captured;
        public int carrier;
    }


    public class Obj
    {
        public Obj(string type_, EndPoint _sender)
        {
            type = type_;
            position = Vector3.Zero;
            sender = _sender;
        }

        internal EndPoint sender;
        public string type;
        public Vector3 position;
 

        public Vector3 UpdatePos(Vector3 pos)
        {
            this.position = pos;
            return position;
        }
    }

    public static class Program
    {
        public static GameManager gameManager = new GameManager();
        public static Thread positionThread;
        public static Thread RecieverThread;

        public static Socket newsock;
        public static EndPoint remote;

        internal static ConcurrentQueue<string> messageQueue = new ConcurrentQueue<string>();

        public static Packet currPacket;


        //static List<Client> players = new List<Client>();
        public static ConcurrentDictionary<int, Client> players = new ConcurrentDictionary<int, Client>();

        public static ConcurrentDictionary<int, Obj> objects = new ConcurrentDictionary<int, Obj>();

        //static Dictionary<int, Vector3> Positions = new Dictionary<int, Vector3>();
        //static ConcurrentDictionary<int, Vector3> Positions = new ConcurrentDictionary<int, Vector3>();
        //static ConcurrentDictionary<int, Vector3> Rotations = new ConcurrentDictionary<int, Vector3>();

        public static int team = 0;
        public static Flag flagA = new Flag();
        public static Flag flagB = new Flag();

        static int GlobalIDCounter = 1001;
        static int ObjIDCounter = 1000;

        static void Main(string[] args)
        {
            int recv;
            // expected packet size. Powers of 2 are good.
            // we want small, optimised packets. 
            byte[] data = new byte[1024];

            //grabbing device IP
            //string hostName = Dns.GetHostName();
            //IPHostEntry IP = Dns.GetHostEntry(hostName);
            //IPAddress address = IPAddress.Parse(IP.AddressList[1].ToString());

            IPAddress address = IPAddress.Parse("127.0.0.1");

            // Our server IP. This is set to local(127.0.0.1) on socket 9050.   
            //If 9050 is firewalled, you might want to try another! 
            IPEndPoint ipep = new IPEndPoint(address, 9050);

            //Make a socket using UDP. 
            //The parameters passed are enums used by the constructor of Socket to configure the socket. 
            newsock = new Socket(address.AddressFamily, SocketType.Dgram, ProtocolType.Udp);

            newsock.Blocking = false;

            newsock.Bind(ipep); //Bind the socket to our given IP and Port

            //If we made it this far without any networking errors, it’s a good start! 
            Console.WriteLine("Socket open...");
            Console.WriteLine("Server IP: " + address.ToString() +"\nServer Port: " + ipep.Port.ToString());

            //who sent data
            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 0);

            //reference to sender data
            remote = (EndPoint)(sender);

            positionThread = new Thread(UpdatePositionsThread);
            positionThread.Start();

            //RecieverThread = new Thread(RecieveMessageThread);
            //RecieverThread.Start();
            //RecieveMessageThread();

            Task.Run(() => RecieveMessageThread());
            //RecieveMessageThread(newsock);

            while (true)
            {
                try
                {

                    //recv = newsock.ReceiveFrom(data, ref remote);

                    //AddClient(remote, newsock);

                    //read the message 
                    //ReadMessage(Encoding.ASCII.GetString(data, 0, recv).ToString(), remote);
                    //Task.Run(() => ReadMessage(Encoding.ASCII.GetString(data, 0, recv).ToString(), remote));
                    try
                    {
                    
                        // Limit the number of messages processed in one frame
                        int maxMessagesToProcess = 10;
                        int processedMessages = 0;
                    
                        while (messageQueue.Count > 0 && processedMessages < maxMessagesToProcess)
                        {
                            string message;
                            //lock (messageQueue)
                            //{
                    
                              messageQueue.TryDequeue(out message);
                            //}
                            Task.Run(() => ReadMessage(message, remote));
                            //ReadMessage(message, remote);
                            processedMessages++;
                        }
                    
                    
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("ERROR IN LOOP: " + e.ToString());
                    }

                }
                catch (SocketException ex)
                {
                    //Console.WriteLine("No data recieved");
                }

                //handle commands
                if (Console.KeyAvailable)
                {
                    string input = Console.ReadLine();

                    bool end = HandleCommand(input, newsock);

                    if (end)
                        break;
                }

            }

            //Console.ReadLine();
            Console.WriteLine("Closing server...");
            Thread.Sleep(3000);
        }

        public static void RecieveMessageThread()
        {
            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 0);
            Packet p;
            byte[] data = new byte[1024];

            while (true)
            {
                try
                {
                    if (newsock.Available > 0)  // Only attempt to receive if data is available
                    {
                        int recv = newsock.ReceiveFrom(data, ref remote);

                        AddClient(remote, newsock);

                        string message = Encoding.ASCII.GetString(data, 0, recv).ToString();
                        //Debug.Log("MESSAGE RECIEVED: \n" + receiveString);

                        //lock (messageQueue)
                        //{
                            messageQueue.Enqueue(message);
                        //Task.Run(() => ReadMessage(message, remote));

                        //}
                    }
                }
                catch (SocketException e)
                {
                    //if we just haven't recieved any data, just dont throw an error
                    if (e.ErrorCode == 10035)  // WSAEWOULDBLOCK error code
                    {
                        // No data available, just continue to the next iteration
                        continue;
                    }
                }

                //Thread.Sleep(1);
            }
        }

        public static void AddClient(EndPoint client, Socket socket)
        {

            TimeSpan currentTime = DateTime.Now.TimeOfDay;

            bool found = false;
            foreach(int i in players.Keys)
            {
                if (players[i].remote.ToString() == client.ToString())
                {
                    found = true;
                    if (currentTime.Subtract(players[i].LastSent).Seconds > 50)
                    {
                        SendMessage("YOUR_ID\n " + players[i].id + "\n" + players[i].team, players[i].id); //send the newest client all the other client ids

                        SendMessage("PLAYER_STATS\n" + players[i].id + "\n" + players[i].kills + "\n" + players[i].deaths + "\n" + players[i].health + "\n" + players[i].Weapon);

                        //if found, still send this player the list of players as they are likely reconnecting
                        foreach (int ID in players.Keys)
                        {
                            SendMessage("PLAYERS\n " + players[ID].id + "\n" + players[ID].team); //send the newest client all the other client ids
                        }

                        SendMessage("MOVE\n " + players[i].PosString(), players[i].id); //send the newest client all the other client ids

                        foreach (int ID in objects.Keys)
                        {   
                            SendMessage("NEW_OBJ" + "\n" + ID.ToString() + "\n" + objects[ID].type); //message[2] is the object type

                            SendMessage("OBJECT_UPDATE" + "\n" + ID.ToString() + "\n" + objects[ID].position.X.ToString() + "\n" + objects[ID].position.Y.ToString() + "\n" + objects[ID].position.Z.ToString());
                        }

                        if (flagA.captured)
                        {
                            SendMessage("FLAG_CAPTURED\n" + flagA.carrier + "\n" + "1"); //1 = id of player who captured //2 = team that captured flag
                        }
                        if (flagB.captured)
                        {
                            SendMessage("FLAG_CAPTURED\n" + flagB.carrier + "\n" + "0"); //1 = id of player who captured //2 = team that captured flag
                        }
                        

                        Client tempC = players[i];
                        tempC.LastSent = currentTime;
                        players[i].LastSent = currentTime;
                        players[i].remote = client;
                    }

                    break;
                }
            }

            if (!found)
            {
                //create the id
                int id;

                //using a static counter to increase the id to a unique ID
                id = GlobalIDCounter;
                players.TryAdd(GlobalIDCounter, new Client(client, id, socket, team));
                GlobalIDCounter++;

                Client tempC = players[id];
                tempC.LastSent = currentTime;
                players[id] = tempC;

                //send three lines, the local id, the global id and the team
                SendMessage("YOUR_ID\n" + players[id].id + "\n" + team, players[id].id); //send the newest client their ID


                foreach (int ID in players.Keys)
                {
                    SendMessage("PLAYERS\n " + players[ID].id + "\n" + players[ID].team); //give update everyone with all the players
                }


                //generate their spawn position
                players[id].SpawnPosition = FindSpawnPosition(team);
                players[id].Position = players[id].SpawnPosition;

                Console.WriteLine("Sending player to: \n" + players[id].PosString());
                SendMessage("MOVE\n" + players[id].PosString(), players[id].id); //send this client their spawn position


                if (flagA.captured)
                {
                    SendMessage("FLAG_CAPTURED\n" + flagA.carrier + "\n" + "1"); //1 = id of player who captured //2 = team that captured flag
                }
                if (flagB.captured)
                {
                    SendMessage("FLAG_CAPTURED\n" + flagB.carrier + "\n" + "0"); //1 = id of player who captured //2 = team that captured flag
                }


                //send all client positions
                UpdateClients();


                //swap team for next player
                team = (team == 0 ? 1 : 0);

                Console.WriteLine("NEW CLIENT");
                Console.WriteLine("Players: ");
                foreach (int ID in players.Keys)
                {
                    Console.WriteLine(players[ID].id);
                }
            }
        }


        public static void SendMessage(string message, int id = -1)
        {
            byte[] data = new byte[1024];
            //Console.WriteLine("Sending " + message);
                
            //Remember we need to convert anything to bytes to send it across the network to the client
            data = Encoding.ASCII.GetBytes(message + "\n");
            //send to all
            if(id == -1)
            {
                foreach (int ID in players.Keys)
                {
                    players[ID].socket.SendTo(data, data.Length, SocketFlags.None, players[ID].remote);
                }
                //Send the bytes for the ‘hi’ string to the remote that just connected. 
                //First parameter is the data, 2nd is packet size, 3rd is any flags we want,
                //and 4th is destination client (which was saved when ReceiveFrom() is called)

                //newsock.SendTo(data, data.Length, SocketFlags.None, client);
            }
            else if(players.IsEmpty == false)
            {
                players[id].socket.SendTo(data, data.Length, SocketFlags.None, players[id].remote);
            }
        }


        //this will run all the time alongside code and ensure clients are always getting positions
        public static void UpdatePositionsThread()
        {
            while (true)
            {

                //if (Positions.Count > 0 && Rotations.Count > 0)
                if (players.Count > 0)
                {
                    foreach (int i in players.Keys)
                    {
                        //if (players[i].moved == true)
                        //{

                        //send positions
                        string message = ("NEW_POSITIONS\n" + i.ToString() + "\n" + players[i].PosString());

                        Program.SendMessage(message);

                        message = ("NEW_ROTATIONS\n" + i.ToString() + "\n" + players[i].RotString());

                        Program.SendMessage(message);

                        //}

                    }


                    //foreach (int ID in objects.Keys)
                    //{
                    //    Program.SendMessage("OBJECT_UPDATE" + "\n" + ID.ToString() + "\n" + objects[ID].position.X.ToString() + "\n" + objects[ID].position.Y.ToString() + "\n" + objects[ID].position.Z.ToString());
                    //}
                }
                else
                {
                    //Console.WriteLine("NO POSITIONS FOUND");
                }

                Thread.Sleep(50);
            }
        }
        static void UpdateClients()
        {
            foreach (int id in players.Keys)
            {
                //string newPos = Positions[id].X.ToString() + "\n" + Positions[id].Y.ToString() + "\n" + Positions[id].Z.ToString();
                SendMessage(("NEW_POSITIONS\n" + id.ToString() + "\n" + players[id].PosString()));
                SendMessage(("NEW_ROTATIONS\n" + id.ToString() + "\n" + players[id].RotString()));
            }

            //We also need to send all the currently active objects
            foreach(int id in objects.Keys)
            {
                SendMessage("NEW_OBJ" + "\n" + id + "\n" + objects[id].type); //.t is the object type
            }
        }

        public static void ReadMessage(string recMessaged, EndPoint remote)
        {
            string[] message = recMessaged.Split('\n');
            //if (message[0] != "POSITIONS" && message[0] != "ROTATIONS")
            //{
            //    Console.WriteLine("Command: " + message[0]);
            //    Console.WriteLine("Full Script: " + recMessaged);
            //}

            int currID = 0;
            //try get the id of the message
            foreach(Client c in players.Values)
            {
                if(c.remote.ToString() == remote.ToString())
                {
                    currID = c.id;
                }
            }

            if (message[0] == "CONNECTING")
            {

                //foreach (int i in players.Keys)
                //{
                //    if (players[i].remote.ToString() == remote.ToString())
                //    {
                //        players[i].LastSent = TimeSpan.MinValue;
                //    }
                //}
                //AddClient(remote, newsock);
            }
            if (message[0] == "ID_REQUEST")
            {
                foreach (int ID in players.Keys)
                {
                    if (players[ID].remote == remote)
                    {
                        Console.WriteLine("ID REQUESTED FROM " + remote.ToString());
                        Console.WriteLine("ID: " + ID);
                        SendMessage("YOUR_ID" + "\n" + ID + "\n" + players[ID].team, players[ID].id);
                    }
                }
            }
            if (message[0] == "DISCONNECTED")
            {
                Console.WriteLine("Player " +  message[1] + " is trying to disconnect"); 
            }
            if (message[0] == "POSITIONS")
            {
                //Console.WriteLine("NEW POSITIONS RECIEVED");
                //Console.WriteLine(recMessaged);

                Vector3 newPos = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                //if (Positions[int.Parse(message[1])] == newPos && int.Parse(message[1]) != 0)
                if (players[int.Parse(message[1])].Position == newPos)
                {
                    //no change to position
                }
                else
                {
                    //position has changed, so update position

                    //Positions[int.Parse(message[1])] = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                    players[int.Parse(message[1])].Position = newPos;
                    //UpdateClients();
                }
            }
            if(message[0] == "ROTATIONS")
            {
                //Quaternion newRot = Quaternion(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                Vector3 newRot;
                newRot.X = float.Parse(message[2]);
                newRot.Y = float.Parse(message[3]);
                newRot.Z = float.Parse(message[4]);
                //if (Rotations[int.Parse(message[1])] == newRot)
                if (players[int.Parse(message[1])].Rotation == newRot)
                {
                        //no change to position
                }
                else
                {   
                    //position has changed, so update position
                    //Rotations[int.Parse(message[1])] = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                    players[int.Parse(message[1])].Rotation = newRot;
                    //UpdateClients();
                }
            }
            if (message[0] == "POSITION_REQUEST")
            {
                //Console.WriteLine("POSITION REQUESTED");
                //Console.WriteLine(recMessaged);
                //string newPos = Positions[int.Parse(message[1])].X.ToString() + "\n" + Positions[int.Parse(message[1])].Y.ToString() + "\n" + Positions[int.Parse(message[1])].Z.ToString();
                string newPos = players[currID].PosString();
                //SendMessage(("NEW_POSITIONS\n" + message[1].ToString() + "\n" + newPos));
                SendMessage("MOVE\n" + newPos, players[int.Parse(message[1])].id);
            }

            if (message[0] == "HIT")
            {
                Console.WriteLine("Player " + message[1] + " is hit");
                currID = int.Parse(message[1]);
                players[currID].health -= int.Parse(message[3]); //return the client data with a modified health value
                Console.WriteLine("Health: " + players[currID].health);


                SendMessage("DAMAGE\n" + message[1] + "\n" + players[currID].health.ToString());

                if (players[currID].health <= 0)
                {
                    SendMessage("DIED\n" + message[1] + "\n" + message[2]);
                        
                    players[int.Parse(message[2])].kills++;
                    players[int.Parse(message[1])].deaths++;
                }
            }

            if (message[0] == "RESPAWN")
            {   
                Console.WriteLine("Player " + message[1] + " has died");

                //find a respawn position
                players[int.Parse(message[1])].Position = players[int.Parse(message[1])].SpawnPosition;
                
                //Send the player to a new respawn position
                string newPos = players[currID].PosString();
                SendMessage("MOVE\n" + newPos, int.Parse(message[1]));


                //Send full health
                players[int.Parse(message[1])].health = 100; //return the client data with a modified health value
                SendMessage("DAMAGE\n" + message[1] + "\n" + players[int.Parse(message[1])].health.ToString());


                //Console.WriteLine("Player " + message[1] + " respawned at: " + Positions[int.Parse(message[1])].ToString());
            }

            if (message[0] == "HEAL")
            {
                if (players[int.Parse(message[1])].health >= 100)
                {
                    players[int.Parse(message[1])].health = 100;
                    return;
                }
                Console.WriteLine("WE GOT HEALS: " + players[int.Parse(message[1])]);
                players[int.Parse(message[1])].health += 10;
                Console.WriteLine("HEALED: " + players[int.Parse(message[1])].health.ToString());
                SendMessage("DAMAGE\n" + message[1] + players[int.Parse(message[1])].health.ToString(), players[int.Parse(message[1])].id);
            }

            if (message[0] == "FLAG_CAPTURED")
            {
                //if team 0 has captured the flag, is team b that has had its flag captured
                if (message[2] == "0")
                {
                    Program.flagA.captured = true;
                    Program.flagA.carrier = int.Parse(message[1]);
                }
                else
                {
                    Program.flagB.captured = true;
                    Program.flagB.carrier = int.Parse(message[1]);
                }

                Console.WriteLine("FLAG IS CAPTURED BY " + message[1]);
                SendMessage("FLAG_CAPTURED\n" + message[1] + "\n" + message[2]); //1 = id of player  who captured //2 = team that captured flag

            }
            if (message[0] == "FLAG_WON")
            {
                if (message[1] == "0")
                {
                    Program.flagA.captured = false;
                    Program.flagA.carrier = 0;
                    SendMessage("FLAG_DROPPED\n" + 0 + "\n");

                }
                else
                {
                    Program.flagB.captured = false;
                    Program.flagB.carrier = 0;
                    SendMessage("FLAG_DROPPED\n" + 1 + "\n");
                }

                Console.WriteLine("FLAG HAS BEEN WON");
                Console.WriteLine("Score: " + gameManager.scoreA);
                gameManager.scored(message[1]);
                Console.WriteLine("Score: " + gameManager.scoreA);
                SendMessage("NEW_SCORE\n" + gameManager.scoreA + "\n" + gameManager.scoreB + "\n" + message[1]);

                //byte[] data = new byte[1024];
                ////Remember we need to convert anything to bytes to send it across the network to the client
                //data = Encoding.ASCII.GetBytes("NEW_SCORE\n");
                //for (int i = 0; i < players.Count; i++)
                //{
                //    socket.SendTo(data, data.Length, SocketFlags.None, players[i].remote);
                //}
            }

            if (message[0] == "FLAG_DROPPED")
            {
                Console.WriteLine("FLAG HAS BEEN DROPPED");
                if (message[1] == "0")
                {
                    flagA.captured = false;
                    flagA.carrier = 0;
                }
                else
                { 
                    flagB.captured = false; 
                    flagB.carrier = 0;
                }

                SendMessage("FLAG_DROPPED\n" + message[1] + "\n");
                
            }

            if (message[0] == "WEAPON_CHANGE")
            {
                SendMessage("WEAPON_CHANGE" + "\n" + message[1] + "\n" + message[2]);
                players[currID].Weapon = int.Parse(message[2]);
            }


            if (message[0] == "NEW_OBJECT")
            {
                objects.TryAdd(ObjIDCounter, new Obj(message[2], remote));

                Console.WriteLine("New " + message[2] + " Local ID: " + message[1] + " | Global ID: " + ObjIDCounter);
                Console.WriteLine("Sending to " + players[currID].id);

                SendMessage("OBJ_ID" + "\n" + message[1] + "\n" + ObjIDCounter + "\n" + message[2], players[currID].id); //message[2] is the object type
                
                SendMessage("NEW_OBJ" + "\n" + ObjIDCounter + "\n" + message[2]); //message[2] is the object type

                ObjIDCounter++;
            }
            if(message[0] == "OBJECT_POSITION")
            {
                Vector3 newPos = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                if (objects.ContainsKey(int.Parse(message[1])))
                {
                    objects[int.Parse(message[1])].position = newPos;
                    SendMessage("OBJECT_UPDATE" + "\n" + message[1] + "\n" + message[2] + "\n" + message[3] + "\n" + message[4]);
                }
            }
            if(message[0] == "OBJECT_DESTROYED")
            {
                Obj removedObj;
                objects.TryRemove(int.Parse(message[1]), out removedObj);
                SendMessage("OBJECT_REMOVED" + "\n" + message[1]);
            }
        }

        static bool HandleCommand(string c, Socket newsock)
        {
            if (c.ToLower() == "help")
            {
                Console.WriteLine(@"
Commands:
close - end the server
kick - kick a player
kickall - kick all players
message - message all player
score - add a point to team A
test object - spawn a test object");
                c = Console.ReadLine();
            }

            if (c.ToLower() == "close")
            {
                Console.WriteLine("End server");
                positionThread.Abort();

                Console.Clear();
                return true;
            }
            if (c.ToLower() == "kick")
            {
                Console.WriteLine("All Player IDs");

                foreach(int i in players.Keys)
                {
                    Console.WriteLine("Player " + players[i].id + "");
                }
                    
                Console.WriteLine("kick which player (just press enter to skip):");
                string input = Console.ReadLine();
                SendMessage("KICKED\n" + input);
                try
                {
                    Client output;
                    players.TryRemove(players[int.Parse(input)].id, out output);
                }
                catch
                {
                    Console.WriteLine("PLAYER NOT FOUND");
                }
            }
            if (c.ToLower() == "kickall")
            {
                foreach(int i in players.Keys)
                {
                    SendMessage("KICKED\n" + i, i);
                }
                gameManager.Reset();

                Console.Clear();
                players.Clear();
                objects.Clear();
                GlobalIDCounter = 1001;
                ObjIDCounter = 1001;
                team = 0;

            }
            if (c.ToLower() == "message")
            {
                SendMessage(Console.ReadLine());
            }
            if (c.ToLower() == "score")
            {
                gameManager.scored("0");
                SendMessage("NEW_SCORE\n" + gameManager.scoreA + "\n" + gameManager.scoreB + "\n" + "0");
            }
            if (c.ToLower() == "test object")
            {
                SendMessage("NEW_OBJ" + "\n" + 10001 + "\n" + "bubble"); //.t is the object type
                SendMessage("OBJECT_UPDATE" + "\n" + 10001 + "\n" + "0\n10\n0"); //.t is the object type
            }

            return false;
        }
    
        public static Vector3 FindSpawnPosition(int team)
        {
            //team 0 starting positions = 10, 1, 10
            //team 1 starting positions = -10, 1, -10

            Vector3 pos = Vector3.Zero;
            float max = 5.0f;
            float min = -5.0f;

            Random random = new Random();
            pos.X = (float)random.NextDouble() * (max - min) + min;
            pos.Y = 2f;
            pos.Z = (float)random.NextDouble() * (max - min) + min;

            if(team == 0)
            {
                pos.X -= 0;
                pos.Z -= 30;
            } 
            if(team == 1)
            {
                pos.X += 0;
                pos.Z += 30;
            }    


            return pos;
        }
    }
}
    


