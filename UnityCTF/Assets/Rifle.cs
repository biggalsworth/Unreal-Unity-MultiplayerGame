using UnityEngine;

public class Rifle : GunClass
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    public override void Shoot()
    {
        if (canShoot)
        {
            RaycastHit camHit;
            // Does the ray intersect any objects excluding the player layer
            if (Physics.Raycast(Camera.main.transform.position, Camera.main.transform.TransformDirection(Vector3.forward), out camHit, Mathf.Infinity))
            {
                Debug.Log("HIT OBJECT: " + camHit.ToString());
                if (camHit.transform.GetComponent<PlayerClientScript>())
                {
                    PlayerClientScript script = camHit.transform.GetComponent<PlayerClientScript>();
                    Debug.Log("HIT PLAYER: " + script.ID);
                    ServerManager.instance.PlayerHit(script, false, GameObject.FindWithTag("Player").GetComponent<PlayerClientScript>().ID);
                }
            }

            StartCoroutine(ShotDelay());
        }
    }

}
