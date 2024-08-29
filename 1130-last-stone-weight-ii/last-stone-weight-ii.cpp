class Solution {
public:
   int lastStoneWeightII(vector<int>& stones) {
    int totalSum = accumulate(stones.begin(), stones.end(), 0);
    int target = totalSum / 2;
    
    vector<int> dp(target + 1, 0);
    
    for (int stone : stones) {
        for (int i = target; i >= stone; --i) {
            dp[i] = max(dp[i], dp[i - stone] + stone);
        }
    }
    
    return totalSum - 2 * dp[target];
}

};