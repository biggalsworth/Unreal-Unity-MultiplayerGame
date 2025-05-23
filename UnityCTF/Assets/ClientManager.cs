using NUnit.Framework;
using System;
using System.Collections.Generic;
using UnityEngine;

public class ClientManager : MonoBehaviour
{
    public int health;
    public int kills;
    public int deaths;

    public List<GameObject> guns;
    GameObject activeGun;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        if(guns.Count > 0)
        {
            activeGun = guns[0];
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ChangeWeapon(int newGun)
    {
        if (activeGun != null)
            activeGun.SetActive(false);

        if(newGun < guns.Count)
        {
            activeGun = guns[newGun];
            activeGun.SetActive(true);
        }

    }

}
