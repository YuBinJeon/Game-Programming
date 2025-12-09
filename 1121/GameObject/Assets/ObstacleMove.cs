using UnityEngine;
public class ObstacleMove : MonoBehaviour
{
    void OnCollisionEnter(Collision collision)
    {
        //Debug.Log(collision.gameObject.name);
        Vector3 direction = transform.position -
   collision.gameObject.transform.position;
        //나의위치에서상대의위치를빼면방향이결정
        direction = direction.normalized * 1000;  //힘결정
        collision.gameObject.GetComponent<Rigidbody>().AddForce(direction);
    }
    float delta = 0f;
    // Start is called before the first frame update
    void Start()
    {
    }
    // Update is called once per frame
    protected void Update()
    {
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition
       , transform.localPosition.y
        , transform.localPosition.z);
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}