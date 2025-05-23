using System;
using Unity.VisualScripting;
using UnityEngine;

public class ObjectManager : MonoBehaviour
{
    public static ObjectManager instance;

    public FlagScript flagA;
    public FlagScript flagB;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        instance = this;
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    public void FlagCaptured(string[] info)
    {
        /*
        GameObject.Find
        GameObject.Find("flag").GetComponent<FlagScript>().carrierID = int.Parse(info[1]);
        GameObject.Find("flag").GetComponent<FlagScript>().carried = true;
        */

        if (int.Parse(info[2]) == flagA.team) //the team should not be the same side, only opposite team can capture the flag
        {
            flagA.carrierID = int.Parse(info[1]);
            flagA.carried = true;
        }
        else if(int.Parse(info[2]) == flagB.team)
        {
            flagB.carrierID = int.Parse(info[1]);
            flagB.carried = true;
        }
    }

    public void FlagDropped(string[] info)
    {
        if (int.Parse(info[1]) == flagA.team) //the team should not be the same side, only opposite team can capture the flag
        {
            flagA.Reset();
        }
        if(int.Parse(info[1]) == flagB.team)
        {
            flagB.Reset();
        }
    }
}
