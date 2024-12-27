class Solution {
public:
    int f(int ind, int k, string &str, vector<vector<int>> &dp, vector<vector<int>> &memo) {
        if (k == 0)
            return (ind == -1) ? 0 : 1e9;  // If no characters remain but we still need partitions, return high cost.
        if (ind == -1)
            return 1e9;  // If no characters remain but partitions are still needed.

        if (memo[ind][k] != -1)
            return memo[ind][k];

        int ans = 1e9;
        for (int j = ind; j >= 0; j--) {
            int steps = dp[j][ind] + f(j - 1, k - 1, str, dp, memo);
            ans = min(ans, steps);
        }

        return memo[ind][k] = ans;
    }

    int palindromePartition(string str, int k) {
        int sz = str.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        vector<vector<int>> memo(sz, vector<int>(k + 1, -1)); // Memoization table for recursive function.

        // Precompute the costs to convert substrings into palindromes.
        for (int len = 2; len <= sz; len++) {
            for (int i = 0; i + len - 1 < sz; i++) {
                int j = i + len - 1;
                if (str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = 1 + dp[i + 1][j - 1];
            }
        }

        // Call the recursive function.
        return f(sz - 1, k, str, dp, memo);
    }
};
