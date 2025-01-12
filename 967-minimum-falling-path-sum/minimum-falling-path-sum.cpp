class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (j < 0 || j >= n)
            return 1e9;
        if (i == m - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = grid[i][j] + f(i + 1, j - 1, grid, dp);
        int down = grid[i][j] + f(i + 1, j, grid, dp);
        int right = grid[i][j] + f(i + 1, j + 1, grid, dp);

        return dp[i][j] = min({left, down, right});
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = grid[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int left = grid[i][j] + (j-1>=0?dp[i+1][j-1]:1e8);// f(i + 1, j - 1, grid, dp);
                int down = grid[i][j] + dp[i+1][j];
                int right = grid[i][j] + (j+1<n?dp[i+1][j+1]:1e8);// f(i + 1, j + 1, grid, dp);

                 dp[i][j] = min({left, down, right});
            }
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};