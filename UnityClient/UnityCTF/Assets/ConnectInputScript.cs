using TMPro;
using UnityEngine;
using UnityEngine.Assertions.Must;
using UnityEngine.UI;
using static UnityEngine.Rendering.DebugUI;

public class ConnectInputScript : MonoBehaviour
{
    public static ConnectInputScript instance;

    public GameObject inputPanel;
    public GameObject ipField;
    public GameObject portField;


    GameObject player;

    string ip;
    string port;

    public ServerManager serverManager;

    public bool GameBegun;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        instance = this;
        GameBegun = false;

        player = GameObject.FindWithTag("Player");

    }

    // Update is called once per frame
    void Update()
    {
        if (GameBegun == false && GameObject.FindWithTag("Player") != null)
        {
            Debug.Log("NO GAME");
            inputPanel.SetActive(true);
            //serverManager.NetworkObjects[0].gameObject.SetActive(false);
            player.SetActive(false);
        }
    }

    public void BeginGame()
    {
        ip = ipField.GetComponent<TMP_InputField>().text;
        port = portField.GetComponent<TMP_InputField>().text;


        Debug.Log(ip.ToString());
        Debug.Log(port.ToString());
        GameBegun = serverManager.Begin(ip.ToString(), int.Parse(port));

        if(GameBegun)
        {
            inputPanel.SetActive(false);
            //serverManager.NetworkObjects[0].gameObject.SetActive(true);
            //GameObject.FindWithTag("Player").SetActive(true);
            player.SetActive(true);
        }
    }

    public void EndGame()
    {
        StopAllCoroutines();
        GameBegun = false;
        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = true;
    }
}
