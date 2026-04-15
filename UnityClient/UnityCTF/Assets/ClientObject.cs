using System.Collections;
using System.Threading.Tasks;
using UnityEngine;

public class ClientObject : MonoBehaviour
{
    ServerManager serverManager;

    public int localID = 0;
    public int GlobalID = 0;

    public bool IsLocal = false;

    public ObjTypes type = ObjTypes.bubble;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        serverManager = ServerManager.instance;

        if (IsLocal)
        {
            localID = serverManager.LocalIDRequest();

            string pos = transform.position.x.ToString() + "\n" + transform.position.y.ToString() + "\n" + transform.position.z.ToString();

            ServerManager.instance.MessageServer("NEW_OBJECT\n" + localID + "\n" + type.ToString() + "\n" + pos);

            //switch (type)
            //{
            //    case ObjTypes.bubble:
            //    break;
            //    case ObjTypes.grenade:
            //        ServerManager.instance.MessageServer("NEW_OBJECT\n" + localID + "\n" + "grenade" + "\n" + pos);
            //        break;
            //    default:
            //        break;
            //}

        }
    }

    // Update is called once per frame
    void Update()
    {
        UpdatePos();
    }

    void UpdatePos()
    {
        //if(GlobalID != 0)
        if (IsLocal == true && GlobalID != 0)
        {
            string pos = transform.position.x.ToString() + "\n" + transform.position.y.ToString() + "\n" + transform.position.z.ToString();
            //StartCoroutine(Server.Message("OBJECT_POSITION\n" + GlobalID + "\n" + pos));
            ServerManager.instance.MessageServer("OBJECT_POSITION\n" + GlobalID + "\n" + pos);
        }

        //yield return new WaitForSeconds(0.01f);
    }
}