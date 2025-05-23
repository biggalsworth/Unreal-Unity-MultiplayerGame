using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;
using System.Net.NetworkInformation;
using UnityEditor.PackageManager;
using Unity.VisualScripting;
using System.Threading;
using System.Xml.Linq;
using UnityEngine.SocialPlatforms.Impl;
using System.Threading.Tasks;
using System.Collections.Concurrent;
using System.Linq;
using UnityEngine.tvOS;
public struct UdpState
{
    public UdpClient u;
    public IPEndPoint e;
}

public enum ObjTypes
{
    bubble,
    grenade,
    H_Pickup
}

public static class Server
{
    public static UdpClient m_client;

    public static IEnumerator Message(string m, UdpClient _client = null)
    {
        if (_client != null)
            m_client = _client;
        Console.WriteLine("SendingMessage: " + m);
        byte[] array = Encoding.ASCII.GetBytes(m + "\n");
        m_client.Send(array, array.Length);
        yield return null;
    }
}


public class ServerManager : MonoBehaviour
{
    public static ServerManager instance;

    public static UdpClient client;
    static UdpState s;

    ConcurrentQueue<string> messageQueue = new ConcurrentQueue<string>();

    public List<PlayerClientScript> NetworkObjects = new List<PlayerClientScript>();
    public Dictionary<int, PlayerClientScript> ClientDictionay = new Dictionary<int, PlayerClientScript>();

    public List<GameObject> ObjectPrefabs = new List<GameObject>();

    public GameObject PlayerContainer;
    public GameObject PlayerPrefab;
    public ConnectInputScript GameConnectionScreen;

    internal static int localIDs = 1000;

    void Awake()
    {

        QualitySettings.vSyncCount = 1;

        Application.targetFrameRate = 120;

        instance = this;

        NetworkObjects.Clear();
        NetworkObjects.Add(GameObject.FindWithTag("Player").GetComponent<PlayerClientScript>());
    }

    public bool Begin(string ipString, int port)
    {
        try
        {
            //device IP
            string hostName = Dns.GetHostName();
            IPHostEntry IP = Dns.GetHostEntry(hostName);
            //IPAddress address = IPAddress.Parse("127.0.0.1");

            //IPAddress address = IPAddress.Parse("127.0.0.1");
            IPAddress address = IPAddress.Parse(ipString);
            //IPEndPoint ip = new IPEndPoint(address, 9050);
            IPEndPoint ip = new IPEndPoint(address, port);
            client = new UdpClient();

            s = new UdpState();
            s.u = client;
            s.e = ip;

            client.Client.Blocking = false;

            client.Connect(ip);

            //If we made it this far without any networking errors, it�s a good start! 
            Debug.Log("Client complete...");

            string myMessage = "CONNECTING\nFROM UNITY";
            byte[] array = Encoding.ASCII.GetBytes(myMessage);
            client.Send(array, array.Length);

            //myMessage = "PLAYER\n" + NetworkObjects.Count;
            //array = Encoding.ASCII.GetBytes(myMessage);
            //client.Send(array, array.Length);
            //
            //myMessage = "ID";
            //array = Encoding.ASCII.GetBytes(myMessage);
            //client.Send(array, array.Length);

            Server.m_client = client;

            //StartCoroutine(AskForPositions());
            IEnumerator RecieveMessage = RecieveMessageThread();
            //updatePosThread.IsBackground = true;
            //updatePosThread.Start();
            StartCoroutine(RecieveMessage);


            if (s.e == null || client.Client == null || client.Client.Connected == false)
            {
                Debug.Log("YOU HAVE BEEN DISCONNECTED OR CONNECTION NOT VALID");
                return false;
            }
            else
            {
                //StartCoroutine(UpdatePositionThread());
                //client.BeginReceive(ReceiveAsyncCallback, s);
                return true;
            }
        }
        catch
        {
            Debug.Log("YOU HAVE BEEN DISCONNECTED OR CONNECTION NOT VALID");
            return false;
        }

        //if(s.e == null)
        //{
        //    Debug.Log("Nobody here");
        //    return false;
        //}
    }


    // Update is called once per frame
    void Update()
    {
        IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, 0);

        //if (client.Client.Connected == false || client.Client == null)
        if (s.e == null || client.Client == null)
        {
            Debug.LogWarning("Cannot message - no connection");
            ConnectInputScript.instance.EndGame();
        }
        else
        {
            try
            {
                //byte[] receiveBytes = client.Receive(ref endPoint);
                //string receiveString = Encoding.ASCII.GetString(receiveBytes);
                //
                ////check the recieving data  
                //CheckRecData(receiveString);
                //StartCoroutine(ReadMessage(receiveString));

                // Limit the number of messages processed in one frame (adjust as necessary)
                int maxMessagesToProcess = 20;
                int processedMessages = 0;
                
                while (messageQueue.Count > 0 && processedMessages < maxMessagesToProcess)
                {
                    string message = null;
                
                    //lock (messageQueue)
                    //{
                        messageQueue.TryDequeue(out message);
                    //}


                    if (message != null)
                        StartCoroutine(ReadMessage(message));
                        //CheckRecData(message);

                    //processedMessages++;
                }

            }
            catch (Exception e)
            {
                Debug.LogError("ERROR IN UPDATE: " + e.ToString());
            }

            SendNewTransform();

        }

    }

    public IEnumerator RecieveMessageThread()
    {
        IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, 0);
        while (true)
        {
            try
            {
                if (client.Available > 0)  // Only attempt to receive if data is available
                {
                    byte[] receiveBytes = client.Receive(ref endPoint);
                    string receiveString = Encoding.ASCII.GetString(receiveBytes);
                    //Debug.Log("MESSAGE RECIEVED: \n" + receiveString);
                    //lock (messageQueue)
                    //{

                    string[] message = receiveString.Split('\n');
                    //dont add this position if this is already the player position
                    
                    if (message[0] == "NEW_POSITIONS")
                    {
                        if (int.Parse(message[1]) == NetworkObjects[0].ID)
                            continue;
                        else
                        {
                            Vector3 pos = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                            PlayerClientScript player = FindPlayer(int.Parse(message[1]));
                            if (player != null)
                            {
                                player.gameObject.transform.position = pos;
                                continue;
                            }
                        }
                    }

                    //StartCoroutine(ReadMessage(receiveString));
                    if (messageQueue.Contains<string>(receiveString))
                    {
                        continue;
                    }
                    else
                    {
                        //StartCoroutine(ReadMessage(receiveString));
                        messageQueue.Enqueue(receiveString);
                    }

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

                Debug.LogError("Error in ReceiveLoop: " + e.Message);
                ConnectInputScript.instance.EndGame();
                StopAllCoroutines();
                client.Client.Disconnect(false);
            }
            yield return new WaitForFixedUpdate();
        }

    }

    public IEnumerator ReadMessage(string message)
    {
        CheckRecData(message);
        yield return null;
    }

    public PlayerClientScript FindPlayer(int SearchingID)
    {
        foreach (PlayerClientScript script in NetworkObjects)
        {
            if (script.ID == SearchingID)
                return script;
        }

        //no player found
        return null;
    }

    //private IEnumerator Message(string message)
    //{
    //    byte[] array = Encoding.ASCII.GetBytes(message + "\n");
    //    client.Send(array, array.Length);
    //    yield return null;
    //}

    public void MessageServer(string message)
    {

        byte[] array = Encoding.ASCII.GetBytes(message + "\n");
        client.Send(array, array.Length);
        //StartCoroutine(Server.Message(message, client));
        //Task.Run(() => Server.Message(message, client));
    }

    //Check received message for commands
    //public void CheckRecData(IPEndPoint endPoint)
    public void CheckRecData(string receiveString)
    {
        //Debug.Log("Position: " + NetworkObjects[0].transform.position.ToString());

        //byte[] receiveBytes = client.Receive(ref endPoint);
        //string receiveString = Encoding.ASCII.GetString(receiveBytes);

        //if (s.e.Port.ToString() == "9050")
        //{
        //Debug.Log("You got a message from the server!");
        string[] message = receiveString.Split('\n');

        if (message[0] == "RESET")
        {
            ZoneCapture[] scripts = GameObject.FindObjectsByType<ZoneCapture>(FindObjectsSortMode.None);
            foreach (ZoneCapture script in scripts)
            {
                script.flag.Reset();
            }
            
            MatchManager.instance.ScoreA = 0;
            MatchManager.instance.ScoreB = 0;
            MatchManager.instance.UpdateScore(0, 0);

        }

        if (message[0] == "YOUR_ID")
        {
            //NetworkObject[0] will always be the client player
            NetworkObjects[0].ID = int.Parse(message[1]);       //set this clients player ID
            NetworkObjects[0].team = int.Parse(message[2]);     //set this clients player team;
            Debug.Log("YOUR ID: " + NetworkObjects[0].ID);
            Debug.Log("YOUR TEAM: " + int.Parse(message[2]));

        }
        if (message[0] == "PLAYER_STATS")
        {
            ClientManager client = FindPlayer(int.Parse(message[1])).gameObject.GetComponent<ClientManager>();
            client.kills = int.Parse(message[2]);
            client.deaths = int.Parse(message[3]);
            client.health = int.Parse(message[4]);
            //if (int.Parse(message[1]) != NetworkObjects[0].ID)
                //client.ChangeWeapon(int.Parse(message[4]));
        }
        if (message[0] == "WEAPON_CHANGE")
        {
            if(int.Parse(message[0]) != NetworkObjects[0].GetComponent<PlayerClientScript>().ID)
            {
                PlayerClientScript client = FindPlayer(int.Parse(message[1]));
                client.gameObject.GetComponent<ClientManager>().ChangeWeapon(int.Parse(message[2]));
            }
        }
        if(message[0] == "OBJ_ID")
        {
            //Debug.Log("DEFINING OBJECT " + message.ToString());

            foreach (ClientObject obj in GameObject.FindObjectsByType(typeof(ClientObject), FindObjectsSortMode.None))
            {
                if(obj.localID == int.Parse(message[1]))
                {
                    obj.GlobalID = int.Parse(message[2]);
                    return;
                }

            }
        }
        if(message[0] == "NEW_OBJ")
        {

            //Debug.Log("NEW OBJECT " + message[1] + " : " + message[2]);
            foreach (ClientObject obj in GameObject.FindObjectsByType<ClientObject>(FindObjectsSortMode.None))
            {
                if (obj.GlobalID == int.Parse(message[1]))
                {
                    return;
                }

            }

            //this object was not found, spawn a new object
            foreach (GameObject obj in ObjectPrefabs)
            {
                if(obj.GetComponent<ClientObject>().type.ToString() == message[2])
                {
                    //spawn this object
                    GameObject _obj = Instantiate(obj, null);
                    _obj.GetComponent<ClientObject>().IsLocal = false;
                    _obj.GetComponent<ClientObject>().GlobalID = int.Parse(message[1]);
                    break;
                }
                /*
                if (obj.GetComponent<ClientObject>().type == ObjTypes.bubble && message[2] == "bubble")
                {
                    //spawn this object
                    GameObject _obj = Instantiate(obj, null);
                    _obj.GetComponent<ClientObject>().IsLocal = false;
                    _obj.GetComponent<ClientObject>().GlobalID = int.Parse(message[1]);
                }
                if (obj.GetComponent<ClientObject>().type == ObjTypes.grenade && message[2] == "grenade")
                {
                    //spawn this object
                    GameObject _obj = Instantiate(obj, null);
                    _obj.GetComponent<ClientObject>().IsLocal = false;
                    _obj.GetComponent<ClientObject>().GlobalID = int.Parse(message[1]);
                }
                */
            }
        }
        if(message[0] == "OBJECT_UPDATE")
        {
            //Debug.Log("NEW OBJECT POSITION: " + new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4])).ToString());
            //if we have this object, find its local id and set its global id to the provided ID
            foreach(ClientObject obj in GameObject.FindObjectsByType<ClientObject>(FindObjectsSortMode.None))
            {
                if(obj.GlobalID == int.Parse(message[1]) && obj.IsLocal == false)
                {
                    obj.gameObject.transform.position = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                }

            }
        }
        if(message[0] == "OBJECT_REMOVED")
        {
            try
            {
                foreach (ClientObject obj in GameObject.FindObjectsByType<ClientObject>(FindObjectsSortMode.None))
                {
                    if (obj.GlobalID == int.Parse(message[1]))
                    {
                        Destroy(obj.gameObject);
                        break;
                    }

                }
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("bullet was already destroyed.\n " + e.Message);
            }
        }


        if (message[0] == "PLAYERS")
        {
            CreatePlayerIDs(message[1], message[2]);
        }
        if (message[0] == "PLAYERSTATS")
        {
            NetworkObjects[0].GetComponent<PlayerCombat>().health = int.Parse(message[2]);
        }
        if (message[0] == "NEW_POSITIONS")
        {
            //Debug.Log(receiveString);
            foreach (PlayerClientScript script in NetworkObjects)
            {
                if (script.ID == int.Parse(message[1]) && script.ID != NetworkObjects[0].ID)
                {
                    //NetworkObjects[int.Parse(message[1])].transform.position = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                    script.transform.position = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                    break;
                }
            }
        }
        if (message[0] == "NEW_ROTATIONS")
        {
            //Debug.Log(receiveString);
            foreach (PlayerClientScript script in NetworkObjects)
            {
                if (script.ID == int.Parse(message[1]) && script != NetworkObjects[0])
                {
                    //NetworkObjects[int.Parse(message[1])].transform.position = new Vector3(float.Parse(message[2]), float.Parse(message[3]), float.Parse(message[4]));
                    // Parse the values to floats
                    float x = float.Parse(message[2]);
                    float y = float.Parse(message[3]);
                    float z = float.Parse(message[4]);

                    // Create a Quaternion from the Euler angles/
                    Vector3 rotationVec = new Vector3(x, y, z);
                    Quaternion rotation = Quaternion.Euler(x, y, z);
                    script.transform.rotation = rotation;

                    break;
                }
            }
        }
        if (message[0] == "MOVE")
        {
            Debug.Log("Moved Command: \n" + receiveString);
            GameObject player = NetworkObjects[0].gameObject;

            //player.GetComponent<CharacterController>().enabled = false;
            //player.GetComponent<PlayerMovement>().enabled = false;

            player.transform.position = new Vector3(float.Parse(message[1]), float.Parse(message[2]), float.Parse(message[3]));
            Debug.Log("New Position: " + GameObject.FindWithTag("Player").transform.position);


            //player.GetComponent<CharacterController>().enabled = true;
            //player.GetComponent<PlayerMovement>().enabled = true;
        }
        if (message[0] == "DAMAGE")
        {
            Console.WriteLine("WE hit");
            if (int.Parse(message[1]) == NetworkObjects[0].ID)
            {
                int health = int.Parse(message[2]);
                NetworkObjects[0].gameObject.GetComponent<PlayerCombat>().health = int.Parse(message[2]); //assign players new health

                //we have been respawned if our health is reset
                if(health == 100)
                {
                    NetworkObjects[0].gameObject.GetComponent<Rigidbody>().WakeUp();
                }
            }
        }
        if (message[0] == "DIED")
        {
            //server manages respawns now
            if (int.Parse(message[1]) == NetworkObjects[0].ID)
            {

                foreach (GameObject obj in ObjectPrefabs)
                {
                    if (obj.GetComponent<ClientObject>().type == ObjTypes.H_Pickup)
                    {
                        GameObject newHealth = Instantiate(obj, NetworkObjects[0].transform.position, Quaternion.Euler(0, 0, 0));
                        newHealth.GetComponent<ClientObject>().IsLocal = true;
                    }
                }

            }

            Debug.Log("Player: " + message[1] + " Died");
            Debug.Log("Player: " + message[2] + " Killed");
            LeaderboardScript.instance.Died(int.Parse(message[1]));    //the first id will be who died
            LeaderboardScript.instance.Killed(int.Parse(message[2]));    //the first id will be who died

            //LeaderboardScript.instance.players[int.Parse(message[1])].Died();  //the second is who killed them
            //LeaderboardScript.instance.players[int.Parse(message[2])].Killed();  //the second is who killed them
        }
        if (message[0] == "KICKED")
        {
            if (NetworkObjects[0].ID != int.Parse(message[1]))
            {
                Debug.Log("PLAYER " + message[1] + "HAS BEEN KICKED");
            }
            else
            {
                MessageServer("DISCONNECTED\n" + NetworkObjects[0].ID);
                client.Client.Disconnect(false);
                Debug.Log("YOU'VE BEEN KICKED");
                s = new UdpState();
            }
            NetworkObjects.Clear();
        }


        if (message[0] == "FLAG_CAPTURED")
        {
            ObjectManager.instance.FlagCaptured(message);
        } 
        if (message[0] == "FLAG_DROPPED")
        {
            ObjectManager.instance.FlagDropped(message);
        }

        if (message[0] == "NEW_SCORE")
        {
            Debug.Log("Team A: " + message[1]);
            Debug.Log("Team B: " + message[2]);

            MatchManager.instance.UpdateScore(int.Parse(message[1]), int.Parse(message[2]));

            ZoneCapture[] scripts = GameObject.FindObjectsByType<ZoneCapture>(FindObjectsSortMode.None);
            foreach (ZoneCapture script in scripts)
            {
                //if the other team just scored with our flag, reset
                if (script.team == int.Parse(message[3]))
                {
                    script.Captured();
                }
            }
        }

        //}

        //Debug.Log("Received " + receiveString + " from " + s.e.ToString());
    }


    void CreatePlayerIDs(string id, string t)
    {
        Debug.Log("NEW ID: " + id);
        Debug.Log("NEW ID INT: " + int.Parse(id));

        PlayerClientScript[] obj = GameObject.FindObjectsByType<PlayerClientScript>(FindObjectsSortMode.None);

        bool found = false;

        foreach (PlayerClientScript player in obj)
        {
            if (player.ID == int.Parse(id.ToString()))
            {
                player.team = int.Parse(t.ToString());

                found = true;
            }
            if (player.ID == 0)
            {
                player.ID = int.Parse(id.ToString());
                player.team = int.Parse(t.ToString());

                found = true;
                break;
            }
            Debug.Log(id);
        }

        if (!found)
        {
            Debug.LogError("WE NEED TO MAKE A NEW PLAYER");

            GameObject newPlayer = GameObject.Instantiate(PlayerPrefab, PlayerContainer.transform);
            newPlayer.GetComponent<PlayerClientScript>().ID = int.Parse(id.ToString());
            newPlayer.GetComponent<PlayerClientScript>().team = int.Parse(t.ToString());
            NetworkObjects.Add(newPlayer.GetComponent<PlayerClientScript>());
            //CreatePlayerIDs(id);

        }

        LeaderboardScript.instance.CreateEntries();
    }

    public void SendNewTransform()
    {
        if (NetworkObjects[0].ID == 0)
        {
            //we have not had an id yet, dont send a position
            return;
        }

        string positionMessage = new string("POSITIONS\n" + NetworkObjects[0].ID.ToString() + "\n" + 
            NetworkObjects[0].transform.position.x.ToString() + "\n" + 
            NetworkObjects[0].transform.position.y.ToString() + "\n" + 
            NetworkObjects[0].transform.position.z.ToString());
        //MessageServer(positionMessage);

        //string rotationMessage = new string("ROTATIONS\n" + NetworkObjects[0].ID.ToString() + "\n" + NetworkObjects[0].transform.localEulerAngles.x.ToString() + "\n" + NetworkObjects[0].transform.localEulerAngles.y.ToString() + "\n" + NetworkObjects[0].transform.localEulerAngles.z.ToString());
        string rotationMessage = new string("ROTATIONS\n" + NetworkObjects[0].ID.ToString() + "\n" + 
            NetworkObjects[0].transform.rotation.eulerAngles.x.ToString() + "\n" +
            NetworkObjects[0].transform.rotation.eulerAngles.y.ToString() + "\n" +
            NetworkObjects[0].transform.rotation.eulerAngles.z.ToString());

        byte[] array = Encoding.ASCII.GetBytes(positionMessage);
        client.Send(array, array.Length);
        array = Encoding.ASCII.GetBytes(rotationMessage);
        client.Send(array, array.Length);
    }
    public IEnumerator AskForPositions()
    {
        while (true)
        {
            if (NetworkObjects.Count < 1)
                continue;
            foreach (PlayerClientScript script in NetworkObjects)
            {
                if (script.ID == 0)
                    break;

                string positionMessage = new string("POSITION_REQUEST\n" + script.ID);
                byte[] array = Encoding.ASCII.GetBytes(positionMessage);
                client.Send(array, array.Length);
            }
            yield return new WaitForSeconds(0.1f);
        }

    }
   
    public void FlagCapture(string id, string team, int code)
    {
        if (code == 0) // flag has been picked up
        {
            string myMessage = "FLAG_CAPTURED\n" + id + "\n" + team;
            byte[] array = Encoding.ASCII.GetBytes(myMessage);
            client.Send(array, array.Length);
        }
        if (code == 1) // flag has been won
        {
            string myMessage = "FLAG_WON\n" + id;
            try
            {
                byte[] array = Encoding.ASCII.GetBytes(myMessage);
                client.Send(array, array.Length);
            }
            catch (Exception e)
            {
                Debug.Log(e.Message);
            }
        }
    }

    public void PlayerHit(PlayerClientScript script, bool respawn = false, int hitterID = 0, int damage = 10)
    {
        string message;
        if (client.Client.Connected == false)
        {
            //Nobody to send data to
            return;
        }
        else
        {
            if (respawn)
            {
                //the player health has reached zero, we need to respawn him;
                message = new string("RESPAWN\n" + script.ID.ToString());
                byte[] array = Encoding.ASCII.GetBytes(message);
                client.Send(array, array.Length);
                return;
            }
            else
            {
                /* hit command
                HIT
                WHO WAS HIT
                WHO DID THE HIT
                 */
                Console.WriteLine(script.ID);
                Console.WriteLine(hitterID);
                Console.WriteLine(damage);
                message = ("HIT\n" + script.ID.ToString() + "\n" + hitterID.ToString() + "\n" + damage.ToString());
                byte[] array = Encoding.ASCII.GetBytes(message);
                client.Send(array, array.Length);
            }
        }

    }

    internal int LocalIDRequest()
    {
        localIDs++;
        return localIDs;
    }

    /*
    void ReceiveAsyncCallback(IAsyncResult ar)
    {
        byte[] receiveBytes = client.EndReceive(ar, ref s.e);
        string receiveString = Encoding.ASCII.GetString(receiveBytes);

        Debug.Log("NEW MESSAGE: " + receiveString);

        if (s.e.Port.ToString() == "9050")
        {
            Debug.Log("You got a message from the server!");
            string[] message = receiveString.Split('\n');

            Debug.Log("Message starts " + message[0]);

            if (message[0] == "YOUR_ID")
            {
                //NetworkObject[0] will always be the client player
                NetworkObjects[0].ID = int.Parse(message[1]);       //set this clients player ID
                NetworkObjects[0].team = int.Parse(message[2]);     //set this clients player team;
                Debug.Log("YOUR ID: " + NetworkObjects[0].ID);
                Debug.Log("YOUR TEAM: " + int.Parse(message[2]));

            }
            if (message[0] == "NEW_PLAYER")
            {
                CreatePlayerIDs(message[1]);
            }
            if (message[0] == "KICKED")
            {
                NetworkObjects.Clear();
                Debug.Log("YOU HAVE BEEN KICKED");
            }


            if (message[0] == "FLAG_CAPTURED")
            {
                ObjectManager.instance.FlagCaptured(message);
            }

            if(message[0] == "NEW_SCORE")
            {
                Debug.Log("Team A: " + message[1]);
                Debug.Log("Team B: " + message[2]);


            }
            
        }
        Debug.Log("Received " + receiveString + " from " + s.e.ToString());

        client.BeginReceive(ReceiveAsyncCallback, s);
    }
    */

}
