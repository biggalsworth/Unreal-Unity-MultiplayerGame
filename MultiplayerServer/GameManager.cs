using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace MultiplayerServer
{
    public class GameManager
    {
        public int scoreA;
        public int scoreB;

        public void scored(string team)
        {
            if(team.ToLower() == "0")
                scoreA += 1;
            if(team.ToLower() == "1")
                scoreB += 1;

            if(scoreA >= 3 || scoreB >= 3)
            {
                Reset();
            }
        }



        public void Reset()
        {
            Program.messageQueue = new ConcurrentQueue<string>();

            scoreA = 0;
            scoreB = 0;

            Program.flagA.carrier = 0;
            Program.flagB.carrier = 0;
            Program.flagA.captured = false;
            Program.flagB.captured = false;

            Program.SendMessage("RESET\n");

            int winner = scoreA > scoreB ? scoreA : scoreB;
            Program.SendMessage("WINNER\n" + winner);

            foreach (Client p in Program.players.Values)
            {
                Vector3 newPos = Program.FindSpawnPosition(p.team);

                p.health = 100;
                p.kills = 0;
                p.deaths = 0;
                Program.players[p.id].Position = newPos;
                Program.SendMessage("MOVE\n" + Program.players[p.id].PosString(), p.id);
                Program.SendMessage("PLAYER_STATS\n" + p.id + "\n" + p.kills + "\n" + p.deaths + "\n" + p.health + "\n" + p.Weapon);

            }

            Program.messageQueue = new ConcurrentQueue<string>();
        }
    }

}
