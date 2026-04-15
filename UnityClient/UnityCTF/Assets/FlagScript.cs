using System;
using UnityEngine;
using UnityEngine.SceneManagement;

public class FlagScript : MonoBehaviour
{
    public bool carried = false;

    public GameObject carryFlag;
    public Transform playerAttach;

    public int carrierID;

    public int team = 1;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        if (carried)
        {
            gameObject.GetComponent<MeshRenderer>().enabled = false;
            carryFlag.SetActive(true);

            foreach (GameObject obj in GameObject.FindGameObjectsWithTag("FlagHolder"))
            {
                if (obj.transform.parent.GetComponent<PlayerClientScript>().ID == carrierID)
                {
                    carryFlag.transform.position = obj.transform.position;
                    carryFlag.transform.parent = obj.transform;
                }
            }
        }
        else
        {
            gameObject.GetComponent<MeshRenderer>().enabled = true;

            carryFlag.SetActive(false);
            carryFlag.transform.position = transform.position;
            carryFlag.transform.parent = null;

        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Player" && !carried && other.GetComponent<PlayerClientScript>().team == team)
        {
            Debug.Log("FLAG CARRIED");
            carried = true;
            carrierID = other.GetComponent<PlayerClientScript>().ID;
            GameObject.FindFirstObjectByType<ServerManager>().GetComponent<ServerManager>().FlagCapture(carrierID.ToString(), other.GetComponent<PlayerClientScript>().team.ToString(), 0);

        }

        if(other.tag == "Player" && carried && other.GetComponent<PlayerClientScript>().team != team)
        {
            Debug.Log("Flag returned");
        }
    }

    internal void Reset()
    {
        carried = false;
        carrierID = 0;

        gameObject.GetComponent<MeshRenderer>().enabled = true;

        carryFlag.SetActive(false);
        carryFlag.transform.position = transform.position;
        carryFlag.transform.parent = null;
    }
}
