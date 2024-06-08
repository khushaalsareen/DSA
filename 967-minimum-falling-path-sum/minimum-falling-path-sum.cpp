class Solution {
public:
    int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp ){
        int n = matrix.size();
        if(j>=n ||j<0) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = matrix[i][j] + f(i+1,j,matrix,dp);
        int right = matrix[i][j] + f(i+1,j+1,matrix,dp);
        int left = matrix[i][j] + f(i+1,j-1,matrix,dp);
        return dp[i][j] = min({down,left,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int j=0;j<matrix.size();j++){
        //     ans = min(ans,f(0,j,matrix,dp));
        // }
        for(int j=0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int down = matrix[i][j] + dp[i+1][j];// f(i+1,j,matrix,dp);
                int right = matrix[i][j]; 
                if(j+1<n)
                right+= dp[i+1][j+1];// f(i+1,j+1,matrix,dp);
                else
                right+=1e9;
                int left = matrix[i][j]; 
                if(j-1>=0)
                left+= dp[i+1][j-1];// f(i+1,j-1,matrix,dp);
                else
                left+=1e9;
                dp[i][j] = min({down,left,right});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};