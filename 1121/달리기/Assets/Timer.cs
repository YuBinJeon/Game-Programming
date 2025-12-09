using UnityEngine;
using TMPro;

public class Timer : MonoBehaviour
{
    public static float time;
    public TMP_Text uiText;

    private void Start()
    {
        time = 0f;
    }

    private void Update()
    {
        if (!GoalArea.goal)
        {
            time += Time.deltaTime;
        }

        int t = Mathf.FloorToInt(time);
        uiText.text = "Time : " + t.ToString();
    }
}
