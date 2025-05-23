using System.Linq;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

public class LoadoutScript : MonoBehaviour
{
    public Transform PlayerHand;
    GameObject player;

    public GameObject PlayerUI;
    public GameObject LoadoutUI;

    bool selecting;
    bool canChange = true;
    int currentLoadout;


    GameObject currentWeapon;

    [Header("Loadout 1")]
    public GameObject Gun1;
    [Header("Loadout 2")]
    public GameObject Gun2;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        selecting = false;
        canChange = true;

        player = GameObject.FindWithTag("Player");

        currentLoadout = 0;

        Selected(0);



    }

    // Update is called once per frame
    void Update()
    {

        //if (ConnectInputScript.instance.GameBegun && PlayerUI.activeSelf == false)
        //{
        //    PlayerUI.SetActive(true);
        //}
        //if(ConnectInputScript.instance.GameBegun == false && PlayerUI.activeSelf == true)
        //{
        //    PlayerUI.SetActive(false);
        //}

        if(ConnectInputScript.instance.GameBegun)
        {
            if (Input.GetKeyDown(KeyCode.Alpha1))
            {
                Selected(0);
            }
            else if (Input.GetKeyDown(KeyCode.Alpha2))
            {
                Selected(1);
            }
        }

    }

    public void Exit()
    {
        selecting = false;

        PlayerUI.SetActive(true);
        LoadoutUI.SetActive(false);

        player.SetActive(true);
    }

    public void LoadoutSelection(InputAction.CallbackContext c)
    {
        //if (c.action.IsPressed())
        //{
        //    canChange = false;
        //
        //    selecting = !selecting;
        //    if (selecting)
        //    {
        //        player.SetActive(false);
        //
        //        PlayerUI.SetActive(false);
        //        LoadoutUI.SetActive(true);
        //
        //        Cursor.lockState = CursorLockMode.None;
        //        Cursor.visible = true;
        //
        //    }
        //    else
        //    {
        //        PlayerUI.SetActive(true);
        //        LoadoutUI.SetActive(false);
        //
        //        player.SetActive(false);
        //
        //    }
        //}

        //if (c.canceled)
        //{
        //    canChange = true;
        //}
    }


    public void Selected(int code)
    {
        if (code < player.GetComponent<PlayerCombat>().Guns.Count())
        {
            ServerManager.instance.MessageServer("WEAPON_CHANGE\n" + player.GetComponent<PlayerClientScript>().ID + "\n" + code);

            //currentWeapon = Instantiate(Gun2, PlayerHand);
            player.GetComponent<PlayerCombat>().activeGun.SetActive(false);
            player.GetComponent<PlayerCombat>().Guns[code].SetActive(true);
            player.GetComponent<PlayerCombat>().activeGun = player.GetComponent<PlayerCombat>().Guns[code];

            player.GetComponent<PlayerCombat>().gunType = code;

            //switch (code)
            //{
            //    case 0:
            //        //currentWeapon = Instantiate(Gun1, PlayerHand);
            //        player.GetComponent<PlayerCombat>().gunType = 0;
            //        break;
            //    case 1:
            //        player.GetComponent<PlayerCombat>().gunType = 1;
            //        break;
            //}
        }
        //Exit();
    }
}
