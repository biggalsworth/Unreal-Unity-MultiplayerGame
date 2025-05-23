using System;
using System.Collections;
using UnityEngine;

public class GunClass : MonoBehaviour
{
    public int damage = 10;
    public float cooldown = 0.5f;

    protected bool canShoot = true;


    public virtual void Shoot()
    {
        Console.WriteLine("Shoot");
    }

    public IEnumerator ShotDelay()
    {
        canShoot = false;
        yield return new WaitForSeconds(cooldown);
        canShoot = true;
    }
}
