using UnityEngine;
using UnityEngine.Rendering;

public class BulletScript : MonoBehaviour
{
    public int speed = 200;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        RaycastHit hit;
        // Does the ray intersect any objects excluding the player layer
        if (Physics.Raycast(Camera.main.transform.position, Camera.main.transform.TransformDirection(Vector3.forward), out hit, Mathf.Infinity))
        {
            transform.LookAt(hit.point);
        }

        GetComponent<Rigidbody>().AddForce(transform.forward * speed * Time.deltaTime, ForceMode.VelocityChange);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.GetComponent<PlayerClientScript>())
        {
            PlayerClientScript script = other.GetComponent<PlayerClientScript>();

            Debug.Log("HIT PLAYER: " + script.ID);
            ServerManager.instance.PlayerHit(script, false, script.ID);
        }

        Destroy(gameObject);
    }
}
