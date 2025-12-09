using UnityEngine;

public class GoalArea : MonoBehaviour
{
    public static bool goal;

    private void Start()
    {
        goal = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            goal = true;
        }
    }
}
