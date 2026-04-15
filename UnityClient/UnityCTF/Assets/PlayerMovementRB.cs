using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovementRB : MonoBehaviour
{
    PlayerInput controls;


    public float maxSpeed = 100f;
    public float sprintSpeed = 600f;
    public float moveSpeed = 500f;
    public float jumpHeight = 20f;

    bool sprinting = false;
    bool crouching = false;

    public float mass = 1f;
    public float gravity = -9.81f;
    float groundDistance = 0.15f;
    internal Vector3 velocity = Vector3.zero;
    Vector3 moveDir;
    float x;
    float z;

    Rigidbody rb;
    [SerializeField]
    private bool isGrounded = false;
    internal bool canMove = true;

    public bool testing = false;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        if (testing)
        {
            Cursor.lockState = CursorLockMode.Locked;
            Cursor.visible = false;
            canMove = true;
        }
        else
        {
            if (ConnectInputScript.instance.GameBegun)
            {
              Cursor.lockState = CursorLockMode.Locked;
              Cursor.visible = false;
            }
            else
            {
                Cursor.lockState = CursorLockMode.None;
                Cursor.visible = true;
            }
            
            if (!canMove && rb.IsSleeping() == false)
            {
                rb.Sleep();
            }
            else if (canMove && rb.IsSleeping() == true)
            {
                //controller.enabled = true;
                rb.WakeUp();
            }
        }
        if (canMove)
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
            if (hit.distance >= transform.localScale.y + groundDistance || hit.collider.isTrigger == true)
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
            velocity.y = 0.0f;
            //velocity.y = rb.linearVelocity.y;

        }
        if (!isGrounded)
        {
            velocity.y += (rb.mass * Physics.gravity.y) * Time.deltaTime;
        }


        ///velocity.y += rb.mass * gravity;
        Vector3 currVelocity = rb.linearVelocity;
        currVelocity.y = velocity.y;
        rb.linearVelocity = currVelocity;


        //if (moveDir.normalized.magnitude >= 0.1f)
        //{
        //rb.linearDamping = 5.0f;
        Vector3 finalDir = transform.forward * moveDir.x + transform.right * moveDir.z;

            if (!isGrounded)
            {
                //currVelocity.x = finalDir.x * moveSpeed * 0.5f * Time.deltaTime;
                //currVelocity.z = finalDir.z * moveSpeed * 0.5f * Time.deltaTime;
                rb.AddForce(finalDir * moveSpeed * 0.75f * Time.deltaTime, ForceMode.VelocityChange);
            }
            //if (!sprinting)
            //{
            //rb.vel = (finalDir * moveSpeed * Time.deltaTime);
            //rb.linearVelocity = finalDir * moveSpeed * Time.deltaTime;
            //rb.AddForce(finalDir * moveSpeed * Time.deltaTime);
            else
            {
                rb.AddForce(finalDir * moveSpeed * Time.deltaTime, ForceMode.VelocityChange);

                //currVelocity.x = finalDir.x * moveSpeed * Time.deltaTime;
                //currVelocity.z = finalDir.z * moveSpeed * Time.deltaTime;
            }
                //rb.AddForce(transform.forward * moveDir.x * moveSpeed * Time.deltaTime, ForceMode.Acceleration);
                //rb.AddForce(transform.right * moveDir.z * moveSpeed * Time.deltaTime, ForceMode.Acceleration);
                //controller.Move(finalDir * moveSpeed * Time.deltaTime);

            //}
            //else
            //{
            //    //rb.AddForce(finalDir * sprintSpeed);
            //    rb.linearVelocity = (finalDir * sprintSpeed * Time.deltaTime);
            //
            //    //controller.Move(finalDir * sprintSpeed * Time.deltaTime);
            //
            //}
        //}

        //JUMP
        //if (Input.GetButtonDown("Jump") && isGrounded)
        //{
        //    velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
        //}

        //Apply gravity
        //velocity.y += gravity * Time.deltaTime;
        //controller.Move(velocity * Time.deltaTime);
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

    public void JumpCallback(InputAction.CallbackContext context)
    {
        if (isGrounded && context.action.IsPressed())
            velocity.y = Mathf.Sqrt(jumpHeight * -1f * Physics.gravity.y);
            //rb.AddForce(Vector3.up * jumpHeight, ForceMode.Impulse);
            //rb.AddForce(Vector3.up * Mathf.Sqrt(jumpHeight * -1f * Physics.gravity.y), ForceMode.VelocityChange);
    }
}
