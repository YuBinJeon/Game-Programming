using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;

public class GameResult : MonoBehaviour
{
    private int highScore;
    public TMP_Text resultTime;
    public TMP_Text bestTime;
    public GameObject parts;

    private void Start()
    {
        if (PlayerPrefs.HasKey("HighScore"))
        {
            highScore = PlayerPrefs.GetInt("HighScore");
        }
        else
        {
            highScore = 999;
        }

        parts.SetActive(false);
    }

    private void Update()
    {
        if (GoalArea.goal)
        {
            parts.SetActive(true);

            int result = Mathf.FloorToInt(Timer.time);
            resultTime.text = "ResultTime " + result;
            bestTime.text = "BestTime " + highScore;

            if (highScore > result)
            {
                PlayerPrefs.SetInt("HighScore", result);
                highScore = result;
            }
        }
    }

    public void OnRetry()
    {
        SceneManager.LoadScene("Main");
    }
}
