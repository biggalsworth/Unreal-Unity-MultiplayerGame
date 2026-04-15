using UnityEngine;

public class BubbleRifle : GunClass
{

    public GameObject shootpoint;

    public GameObject bubbleBullet = null;

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
            for (int i = 0; i < GameObject.FindWithTag("Gun").transform.childCount; i++)
            {
                if (GameObject.FindWithTag("Gun").transform.GetChild(0).name == "Shootpoint")
                {
                    shootpoint = GameObject.FindWithTag("Gun").transform.GetChild(0).gameObject;
                }
            }
            GameObject bullet = Instantiate(bubbleBullet, shootpoint.transform.position, transform.rotation, null);
            bullet.GetComponent<Rigidbody>().linearVelocity = GameObject.FindWithTag("Player").GetComponent<Rigidbody>().linearVelocity * 1.5f;
            bullet.GetComponent<ClientObject>().IsLocal = true;

            StartCoroutine(ShotDelay());
        }
    }
}
