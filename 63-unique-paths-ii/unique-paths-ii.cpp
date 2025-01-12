class Solution {
public:
     int f(int i, int j, vector<vector<int>>& dp,vector<vector<int>>&mat) {
        if (i < 0 || j < 0)
            return 0;
        
        if(mat[i][j]==1)
        return 0;

        if (i == 0 && j == 0)
            return 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int left = f(i, j - 1, dp,mat);
        int up = f(i - 1, j, dp,mat);
        return dp[i][j] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};