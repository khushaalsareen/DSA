class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int m = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: one way to get sum 0 with 0 dice
        dp[0][0] = 1;
        
        // Fill the DP table
        for (int dice = 1; dice <= n; ++dice) {
            for (int sum = 1; sum <= target; ++sum) {
                dp[dice][sum] = 0;
                for (int face = 1; face <= k; ++face) {
                    if (sum - face >= 0) {
                        dp[dice][sum] = (dp[dice][sum] + dp[dice - 1][sum - face]) % m;
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};
