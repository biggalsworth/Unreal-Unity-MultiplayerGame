using NUnit.Framework;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerCombat : MonoBehaviour
{

    public int health = 100;
    public int gunType = 0;
    bool died;
    bool canShoot;
    bool canGrenade = true;

    int m_ID;


    public GameObject bubbleBullet;
    GameObject shootpoint;

    public GameObject GrenadePrefab;

    RaycastHit camHit;


    internal GameObject activeGun = null;
    public List<GameObject> Guns;


    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        died = false;
        canShoot = true;

        m_ID = gameObject.GetComponent<PlayerClientScript>().ID;

        activeGun = Guns[0];
    }

    // Update is called once per frame
    void Update()
    {
        if(health <= 0 && died == false)
        {
            foreach( FlagScript flag in GameObject.FindObjectsByType<FlagScript>(FindObjectsSortMode.None))
            {
                if(flag.carrierID == GetComponent<PlayerClientScript>().ID)
                {
                    flag.Reset();
                    ServerManager.instance.MessageServer("FLAG_DROPPED\n" + flag.team);
                }
            }
            died = true;
            GetComponent<Rigidbody>().Sleep();
            ServerManager.instance.PlayerHit(gameObject.GetComponent<PlayerClientScript>(), true);

        }
        if (health == 100 && died == true)
        {
            GetComponent<Rigidbody>().WakeUp();
            died = false;
        }
    }


    public void Shoot()
    {
        if(canShoot == false)
        {
            return;
        }
        try
        {
            Guns[gunType].GetComponent<GunClass>().Shoot();
        }
        catch (Exception e)
        {
            Debug.LogException(e);
        }

        //switch (gunType)
        //{
        //    case 0:
        //        Guns[0].GetComponent<GunClass>().Shoot();
        //        //RayShot();
        //        break;
        //
        //    case 1:
        //        Guns[1].GetComponent<GunClass>().Shoot();
        //        Console.WriteLine("Bubble Shot");
        //        BubbleShot();
        //        break;
        //
        //    default:
        //        Console.WriteLine("NO SHOT SCRIPT FOR THIS GUN!");
        //        break;
        //}
        //StartCoroutine(ShotDelay());
    }

    void RayShot()
    {
        // Does the ray intersect any objects excluding the player layer
        if (Physics.Raycast(Camera.main.transform.position, Camera.main.transform.TransformDirection(Vector3.forward), out camHit, Mathf.Infinity))
        {   
            Debug.Log("HIT OBJECT: " + camHit.ToString());
            if (camHit.transform.GetComponent<PlayerClientScript>())
            {
                PlayerClientScript script = camHit.transform.GetComponent<PlayerClientScript>();
                Debug.Log("HIT PLAYER: " + script.ID);
                ServerManager.instance.PlayerHit(script, false, gameObject.GetComponent<PlayerClientScript>().ID);
            }
        }
    }

    void BubbleShot()
    {
        for(int i = 0; i < GameObject.FindWithTag("Gun").transform.childCount; i++)
        {
            if (GameObject.FindWithTag("Gun").transform.GetChild(0).name == "Shootpoint")
            {
                shootpoint = GameObject.FindWithTag("Gun").transform.GetChild(0).gameObject;
            }
        }
        GameObject bullet = Instantiate(bubbleBullet, shootpoint.transform.position, transform.rotation, null);
        bullet.GetComponent<Rigidbody>().linearVelocity = GetComponent<CharacterController>().velocity * 5.0f;
        bullet.GetComponent<ClientObject>().IsLocal = true;

    }

    public void Grenade(InputAction.CallbackContext context)
    {
        Debug.Log("throwing grenade");
        if(canGrenade)
        {
            //if (Physics.Raycast(Camera.main.transform.position, Camera.main.transform.TransformDirection(Vector3.forward), out camHit, Mathf.Infinity))
            //{
            //
            //}
            GameObject grenade = Instantiate(GrenadePrefab, transform.position + (transform.forward * 1.5f), Camera.main.transform.rotation, null);
            grenade.GetComponent<ClientObject>().IsLocal = true;
            StartCoroutine(GrenadeDelay());
        }
    }

    IEnumerator ShotDelay()
    {
        canShoot = false;
        yield return new WaitForSeconds(0.5f);
        canShoot = true;
    }

    IEnumerator GrenadeDelay()
    {
        canGrenade = false;
        yield return new WaitForSeconds(1.0f);
        canGrenade = true;
    }
}
