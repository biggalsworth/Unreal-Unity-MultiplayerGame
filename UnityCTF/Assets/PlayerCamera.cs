using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerCamera : MonoBehaviour
{
    public Transform cam;
    public Transform Head;

    public float VertSensitivity = 4f;
    public float HorizSensitivity = 3f;
    float xRotation = 0;
    float yRotation = 0;
    public bool invertX = false;
    public bool invertY = false;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    public void UpdateLook(InputAction.CallbackContext context)
    {
        //Position of mouse
        float mouseX = context.ReadValue<Vector2>().x * VertSensitivity * Time.deltaTime;
        float mouseY = context.ReadValue<Vector2>().y * HorizSensitivity * Time.deltaTime;

        xRotation = invertX ? xRotation + mouseY : xRotation - mouseY;
        // -= mouseY;
        //Does not allow to twist backward
        xRotation = Mathf.Clamp(xRotation, -45f, 45f);

        yRotation = invertY ? yRotation - mouseX : yRotation + mouseX;
        //yRotation += mouseX;

        //Use quaternions to rotate
        Head.rotation = Quaternion.Euler(xRotation, yRotation, 0f);
        transform.localRotation = Quaternion.Euler(0, yRotation, 0f);

    }
}
