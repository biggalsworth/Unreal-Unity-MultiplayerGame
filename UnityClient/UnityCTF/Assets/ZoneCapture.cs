using System;
using UnityEngine;

public class ZoneCapture : MonoBehaviour
{
    public int team = 0;
    GameObject server;

    bool Entered;
    internal FlagScript flag;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        server = GameObject.FindFirstObjectByType<ServerManager>().gameObject;

        //server.GetComponent<ServerManager>().FlagCapture(team.ToString(), "NO TEAM", 1);
        FlagScript[] flags = GameObject.FindObjectsByType<FlagScript>(FindObjectsSortMode.None);

        foreach (FlagScript f in flags)
        {
            if (f.team == team)
            {
                //flag.Reset();
                flag = f;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.GetComponent<PlayerClientScript>() != null && other.tag == "Player" && flag.carrierID != 0)
        {
            PlayerClientScript script = other.gameObject.GetComponent<PlayerClientScript>();
            if (script.team == team && flag.carrierID == script.ID)
            {
                server.GetComponent<ServerManager>().FlagCapture(script.team.ToString(), "NO TEAM", 1);
                flag.Reset();
            }
        }
    }

    internal void Captured()
    {
        flag.Reset();
    }
}
