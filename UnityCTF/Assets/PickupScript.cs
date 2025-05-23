using System.Text;
using System;
using UnityEditor.PackageManager;
using UnityEngine;

public class PickupScript : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        //only local player can pickup, if they are alive
        if(other.tag == "Player" && other.GetComponent<PlayerCombat>().health > 0)
        {
            Debug.Log("HEALING");

            byte[] array = Encoding.ASCII.GetBytes("HEAL" + "\n" + other.gameObject.GetComponent<PlayerClientScript>().ID.ToString() + "\n");
            ServerManager.client.Send(array, array.Length);
            StartCoroutine(Server.Message("OBJECT_DESTROYED\n" + GetComponent<ClientObject>().GlobalID));
            Destroy(gameObject);

            //ServerManager.instance.MessageServer("HEAL" + "\n" + other.gameObject.GetComponent<PlayerClientScript>().ID.ToString());
        }
    }
}
