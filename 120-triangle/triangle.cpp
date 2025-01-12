class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        int m = grid.size();
        if(i == m-1)
        return grid[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down = grid[i][j] + f(i+1,j,grid,dp);
        int right = grid[i][j] + f(i+1,j+1,grid,dp);
        return dp[i][j] = min(down,right);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(0,0,grid,dp);
    }
};