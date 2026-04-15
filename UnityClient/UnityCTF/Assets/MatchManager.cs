using TMPro;
using UnityEngine;

public class MatchManager : MonoBehaviour
{
    public static MatchManager instance;

    public int ScoreA;
    public int ScoreB;


    public TextMeshProUGUI teamA;
    public TextMeshProUGUI teamB;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        instance = this;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void UpdateScore(int a, int b)
    {
        ScoreA = a;
        ScoreB = b;

        teamA.text = ScoreA.ToString();
        teamB.text = ScoreB.ToString();
    }
}
