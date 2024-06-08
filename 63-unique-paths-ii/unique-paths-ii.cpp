class Solution {
public:
     int f(int i, int j, int m, int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1)
        return 0;
        if(i==0 && j==0) return 1;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        int left = f(i,j-1,m,n,dp,obstacleGrid);
        int up = f(i-1,j,m,n,dp,obstacleGrid);
        return dp[i][j]= left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp,obstacleGrid);
    }
};