using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    CharacterController controller;

    public float maxSpeed = 10f;
    public float sprintSpeed = 10f;
    public float moveSpeed = 6f;
    public float jumpHeight = 5f;

    bool sprinting = false;
    bool crouching = false;

    public float mass = 1f;
    public float gravity = -9.81f;
    float groundDistance = 0.1f;
    internal Vector3 velocity = Vector3.zero;

    PlayerInput controls;

    Rigidbody rb;

    Vector3 moveDir;
    float x;
    float z;

    public Transform cam;

    private bool isGrounded = false;
    internal bool canMove = true;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        controller = GetComponent<CharacterController>();
        //rb = GetComponent<Rigidbody>();
        moveDir = Vector3.zero;

        //Cursor.lockState = CursorLockMode.Locked;
        //Cursor.visible = false;

    }

    // Update is called once per frame
    void Update()
    {
        if(ConnectInputScript.instance.GameBegun)
        {
          Cursor.lockState = CursorLockMode.Locked;
          Cursor.visible = false;
        }
        else
        {
            Cursor.lockState = CursorLockMode.None;
            Cursor.visible = true;
        }


        if(!canMove && controller.enabled)
        {
            controller.enabled = false;
        }
        else if(canMove && controller.enabled == false)
        {
            controller.enabled = true;
        }

        MovementUpdates();
    }

    void MovementUpdates()
    {
        //Reference a raycast
        RaycastHit hit;

        //Activate downRay
        Ray downRay = new Ray(transform.position, -Vector3.up);

        //When the raycast is shot down...
        if (Physics.Raycast(downRay, out hit))
        {
            //Detects if I am on the ground by shooting raycast downward and detecting 
            //the distance.
            //if (hit.distance >= controller.height/2 + groundDistance)
            if (hit.distance >= transform.localScale.y + groundDistance)
            {
                    //Not allowed to jump (not on the ground)
                    isGrounded = false;
            }
            else
            {
                //Allowed to jump (on the ground)
                isGrounded = true;
            }
        }

        if (isGrounded && velocity.y < 0)
        {
            //velocity.y = -2f;
            velocity.y = -0.5f;
        }



        if (moveDir.normalized.magnitude >= 0.1f)
        {
            Vector3 finalDir = transform.forward * moveDir.x + transform.right * moveDir.z;

            if(!sprinting)
            {
                controller.Move(finalDir * moveSpeed * Time.deltaTime);

            }
            else
            {
                controller.Move(finalDir * sprintSpeed * Time.deltaTime);

            }
        }

        //JUMP
        //if (Input.GetButtonDown("Jump") && isGrounded)
        //{
        //    velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
        //}

        //Apply gravity
        velocity.y += gravity * Time.deltaTime;
        controller.Move(velocity * Time.deltaTime);
    }

    public void MoveCallback(InputAction.CallbackContext context)
    {
        //moveDir = new Vector3(context.ReadValue<Vector2>().x, moveDir.y, context.ReadValue<Vector2>().y);

        moveDir.x = context.ReadValue<Vector2>().y;
        moveDir.z = context.ReadValue<Vector2>().x;

        x = context.ReadValue<Vector2>().y;
        z = context.ReadValue<Vector2>().x;
    }

    public void SprintCallback(InputAction.CallbackContext context)
    {
        if (context.performed) 
        {
            sprinting = true;
        }
        if (context.canceled || crouching) 
        {
            sprinting = false;
        }
    }

    public void CrouchCallback(InputAction.CallbackContext context)
    {
        if (context.performed)
        {
            //if crouch while sprint, slide
            if (sprinting)
            {
                StartCoroutine(Slide());
            }

            crouching = true;

            //squash the object and move it a little down so it doesn't jump
            transform.position = new Vector3(transform.position.x, transform.position.y - 0.75f, transform.position.z);
            transform.localScale = new Vector3(transform.localScale.x, 0.75f, transform.localScale.z);
            //adjust the controller to the new height.
            controller.height = 1.44f;

            //adjust to a slower movement speed
            moveSpeed -= 2f;
        }
        if (context.canceled)
        {
            crouching = false;
            
            //return original scale
            transform.position = new Vector3(transform.position.x, transform.position.y + 0.75f, transform.position.z);
            transform.localScale = new Vector3(transform.localScale.x, 1.0f, transform.localScale.z);
            controller.height = 1.9f;

            moveSpeed += 2f;
        }
    }
    IEnumerator Slide()
    {
        controller.Move((transform.forward * moveDir.x + transform.right * moveDir.z) * 20f * Time.deltaTime);
        yield return new WaitForSeconds(1f);
        sprinting = false;
    }

    public void Jump()
    {
        if (isGrounded)
        {
            velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
        }
    }

}
