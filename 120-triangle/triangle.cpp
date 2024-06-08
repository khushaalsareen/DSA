class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>&dp){
        int n = triangle.size();
        if(i==n-1)
        return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j] + f(i+1,j,triangle,dp);
        int right = triangle[i][j] + f(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),0));
        // return f(0,0,triangle,dp);
        for(int j=0;j<triangle.size();j++){
            dp[triangle.size()-1][j] = triangle[triangle.size()-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                 int right = triangle[i][j] + dp[i+1][j+1];// f(i+1,j+1,triangle,dp);
                dp[i][j] = min(down,right);
            }
        }
        return dp[0][0];
    }
};