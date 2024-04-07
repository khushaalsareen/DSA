class Solution {
public:
    int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = matrix[i][j]+  f(i+1,j,matrix,dp);
        int left = matrix[i][j]+ f(i+1,j-1,matrix,dp);
        int right = matrix[i][j]+ f(i+1,j+1,matrix,dp);

        return dp[i][j] = min({down,left,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1e9;
        vector<vector<int>>dp(m,vector<int>(n,0));
     
        for(int j=0;j<n;j++){
            dp[m-1][j] = matrix[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int down = matrix[i][j] +  dp[i+1][j];
                int left = matrix[i][j]; 
                if(j-1>=0)
                left+=dp[i+1][j-1];
                else
                left+=1e9;
                int right = matrix[i][j];
                if(j+1<n) 
                right+=dp[i+1][j+1];//f(i+1,j+1,matrix,dp);
                else right+=1e9;

                dp[i][j] = min({down,left,right});
            }
        }
        
        for(auto it:dp[0])
        ans = min(ans,it);

        return ans;
    }
};

