using System.Collections;
using System.Threading.Tasks;
using UnityEditor.ShaderGraph.Internal;
using UnityEngine;

public class GrenadeScript : MonoBehaviour
{
    Rigidbody rb;

    int damage = 80;
    public float throwStrength = 15.0f;
    public float timer = 7.0f;
    public float countdown = 0.0f;
    public float radius = 2f;

    public AudioClip Beep;
    public AudioClip Explosion;
    public GameObject ExplosionFX;

    bool explode = false;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        rb = GetComponent<Rigidbody>();

        if(GetComponent<ClientObject>().IsLocal == true)
            rb.AddForce(transform.forward * throwStrength, ForceMode.Impulse);

        rb.AddTorque(Vector3.right * 5.0f, ForceMode.VelocityChange); //spin the grenade forward#

        StartCoroutine(Countdown());
    }

    // Update is called once per frame
    void Update()
    {

    }
    void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, radius);
    }

    IEnumerator Countdown()
    {
        while(countdown < timer)
        {
            GetComponent<AudioSource>().PlayOneShot(Beep);
            GetComponent<AudioSource>().pitch += 0.1f;
            yield return new WaitForSeconds(1.0f);
            countdown += 1.0f;
        }

        explode = true;

        if (explode)
        {
            explode = false;

            RaycastHit[] hit;

            Vector3 p1 = transform.position;

            // Cast a sphere wrapping character controller 10 meters forward
            // to see if it is about to hit anything.
            hit = Physics.SphereCastAll(p1, radius, transform.forward, radius);
            foreach (RaycastHit obj in hit)
            {
                Debug.Log(obj.transform.name);
                if (obj.transform.gameObject.GetComponent<PlayerClientScript>() == null)
                    continue;

                if (obj.transform.GetComponent<Rigidbody>() != null)
                {
                    obj.transform.GetComponent<Rigidbody>().AddExplosionForce(1500.0f, transform.position, radius);

                }
                if (gameObject.GetComponent<ClientObject>().IsLocal)
                {

                    ServerManager.instance.PlayerHit(obj.transform.GetComponent<PlayerClientScript>(), false, GameObject.FindWithTag("Player").GetComponent<PlayerClientScript>().ID, damage);
                    //ServerManager.instance.MessageServer("HIT\n" + obj.transform.GetComponent<PlayerClientScript>().ID + "\n" + GameObject.FindWithTag("Player").GetComponent<PlayerClientScript>().ID.ToString() + "\n" + damage.ToString());

                }

            }


        }

        Instantiate(ExplosionFX, transform.position, transform.rotation);

        if (gameObject.GetComponent<ClientObject>().IsLocal)
        {
            ServerManager.instance.MessageServer("OBJECT_DESTROYED\n" + GetComponent<ClientObject>().GlobalID);
            Destroy(gameObject);
            transform.position = new Vector3(0, -700, 0);
        }

        yield return new WaitForSeconds(0.1f);
    }
}
