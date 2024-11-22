class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[1][0] = 0; // Start with 1 'A' and no copied characters.

        for (int curr = 1; curr < n; ++curr) {
            for (int copied = 0; copied <= curr; ++copied) {
                if (dp[curr][copied] == INT_MAX)
                    continue;

                // Paste Operation
                if (curr + copied <= n) {
                    dp[curr + copied][copied] = min(dp[curr + copied][copied], dp[curr][copied] + 1);
                }

                // Copy All Operation
                dp[curr][curr] = min(dp[curr][curr], dp[curr][copied] + 1);
            }
        }

        // Find the minimum operations to get exactly 'n' A's
        int result = INT_MAX;
        for (int copied = 0; copied <= n; ++copied) {
            result = min(result, dp[n][copied]);
        }

        return result;
    }
};
