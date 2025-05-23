using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerClientScript : MonoBehaviour
{
    [SerializeField]
    internal int ID = 0;
    public int LocalID;

    public bool isLocal;

    public int team;

    void Start()
    {
        LocalID = ServerManager.instance.LocalIDRequest();
    }

    void Update()
    {

    }


}
