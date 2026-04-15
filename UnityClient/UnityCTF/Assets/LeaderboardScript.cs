using NUnit.Framework;
using System;
using System.Collections.Generic;
using TMPro;
using UnityEditorInternal.Profiling.Memory.Experimental;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.LowLevel;
using UnityEngine.SceneManagement;

public class PlayerStats
{
    public GameObject playerEntry;
    public int kills;
    public int deaths;
    public int ping;
    public PlayerStats(GameObject obj) 
    { 
        playerEntry = obj; 

        kills = 0;
        deaths = 0;
        ping = 0;
    }

    public void Died() { Debug.Log("DIIIIIIED"); deaths++; }
    public void Killed() { kills++; }
}


public class LeaderboardScript : MonoBehaviour
{
    public static LeaderboardScript instance;

    public GameObject Leaderboard;

    public GameObject itemPrefab;

    public GameObject team0;
    public GameObject team1;

    [SerializeField]
    public Dictionary<int, PlayerStats> players = new Dictionary<int, PlayerStats>();
    bool show;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Awake()
    {
        instance = this;

        CreateEntries();

        show = false;
        Leaderboard.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        if (show)
        {
            //if (players.Count < ServerManager.NetworkObjects.Count)
            if (players.Count < ServerManager.instance.NetworkObjects.Count)
            {
                foreach (int id in players.Keys)
                {
                    Debug.Log("CURR DEATHS:" + players[id].deaths);
                    Destroy(players[id].playerEntry);
                }

                CreateEntries();
            }

            //if (players.Count > 0)
            //CreateEntries();

        }
        else
        {
            foreach (int id in players.Keys)
            {
                Debug.Log("CURR DEATHS:" + players[id].deaths);
                Destroy(players[id].playerEntry);
            }
            players.Clear();
        }
    }

    public void ToggleLeaderboard(InputAction.CallbackContext c)
    {
        if(c.performed)
        {
            Leaderboard.SetActive(true);
            show = true;
        }
        if(c.canceled)
        {
            Leaderboard.SetActive(false);
            show = false;
        }
    }

    private void UpdateEntries()
    {
        foreach (int id in players.Keys)
        {
            Debug.Log("CURR DEATHS:" + players[id].deaths);
            players[id].playerEntry.transform.GetChild(0).GetComponent<TextMeshProUGUI>().text = "Player" + id;
            players[id].playerEntry.transform.GetChild(1).GetComponent<TextMeshProUGUI>().text = "Deaths: " + players[id].deaths.ToString();
            players[id].playerEntry.transform.GetChild(2).GetComponent<TextMeshProUGUI>().text = "Kills: " + players[id].kills.ToString();
        }
    }

    public void Died(int id)
    {
        players[id].deaths++;
    }
    public void Killed(int id)
    {
        players[id].kills++;
    }

    public void CreateEntries()
    { 
        //int difference = ServerManager.NetworkObjects.Count - players.Count;
        int difference = ServerManager.instance.NetworkObjects.Count - players.Count;

        int team = 0;
        int id = 0;
        GameObject newItem = null;

        PlayerStats stats;
        players.Clear();

        for(int i = 0; i <= difference - 1; i++)
        {
            PlayerClientScript script = ServerManager.instance.NetworkObjects[i];
            id = script.ID;
            if (id == 0)
            {
                return;
            }

            if (players.ContainsKey(id) == false)
            {
                if (script.team == 0)
                    newItem = GameObject.Instantiate(itemPrefab, team0.transform);
                else if(script.team == 1)
                    newItem = GameObject.Instantiate(itemPrefab, team1.transform);

                //newItem.GetComponent<TextMeshProUGUI>().text = "Player" + id;

                players.Add(id, new PlayerStats(newItem));
                players[id].kills = script.gameObject.GetComponent<ClientManager>().kills;
                players[id].deaths = script.gameObject.GetComponent<ClientManager>().deaths;
                Debug.Log("Leaderboard:" + id);
            }
        }

        UpdateEntries();
        /*

        for (int i = 0; i < 10; i++)
        {

            //PlayerClientScript client = ServerManager.NetworkObjects[(players.Count - 1) + i];
            //if(client.team == 0)
            if (team == 0)
            {
                newItem = GameObject.Instantiate(itemPrefab, team0.transform);
                //TextMeshProUGUI newText = TextMeshProUGUI.Instantiate(new TextMeshProUGUI(), team1.transform);

                newItem.GetComponent<TextMeshProUGUI>().text = "Player" + i;

                //players.Add(newItem);

            }
            //else if(client.team == 1)
            else if(team == 1)
            {
                newItem = GameObject.Instantiate(itemPrefab, team1.transform);
                //TextMeshProUGUI newText = TextMeshProUGUI.Instantiate(new TextMeshProUGUI(), team1.transform);

                newItem.GetComponent<TextMeshProUGUI>().text = "Player" + i;

                //players.Add(newItem);

            }


            team = team == 0 ? 1 : 0;
        }
        */
    }
}
