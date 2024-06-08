class Solution {
public:
    int f(int i, int j, int m, int n,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = f(i,j-1,m,n,dp);
        int up = f(i-1,j,m,n,dp);
        return dp[i][j]= left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        // return f(m-1,n-1,m,n,dp);
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0  && j==0) continue;
                else{
                    int left = j-1>=0?dp[i][j-1]:0;
                    int up = i-1>=0?dp[i-1][j]:0;
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};