class Solution {
public:
    int f(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = f(i-1,j,obstacleGrid,dp);
        int left = f(i,j-1,obstacleGrid,dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m = obstacleGrid.size();
         int n = obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,0));
        //  return f(m-1,n-1,obstacleGrid,dp);
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0) continue;
                else
                {
                 int up = 0, left = 0;
                 if(i!=0)
                 up = dp[i-1][j];//  (i-1,j,obstacleGrid,dp);
                 if(j!=0)
                 left =dp[i][j-1]; // f(i,j-1,obstacleGrid,dp);
                dp[i][j] = up + left; 
                }

            }
        }
        return dp[m-1][n-1];
    }
};