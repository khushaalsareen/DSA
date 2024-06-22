class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        int n = cardPoints.size();
        for(int i =0;i<k;i++){
            score+=cardPoints[i];
        }
        int maxScore = score;
        for(int i=0;i<k;i++){
            int leftVal = cardPoints[k-1-i];
            score-=leftVal;
            score+=cardPoints[n-1-i];
            maxScore = max(score,maxScore);
        }
        return maxScore;
    }
};