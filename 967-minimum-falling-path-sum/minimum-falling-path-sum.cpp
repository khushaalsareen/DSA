// class Solution {
// public:
//     int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
//         if(j<0 || j>=matrix[0].size()) return 1e9;
//         if(i==matrix.size()-1) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down = matrix[i][j]+  f(i+1,j,matrix,dp);
//         int left = matrix[i][j]+ f(i+1,j-1,matrix,dp);
//         int right = matrix[i][j]+ f(i+1,j+1,matrix,dp);

//         return dp[i][j] = min({down,left,right});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int ans = 1e9;
//         vector<vector<int>>dp(m,vector<int>(n,0));
//         // for(int i=0;i<n;i++){
//         //     ans = min(ans,f(0,i,matrix,dp));
//         // }
//         for(int j=0;j<n;j++){
//             dp[m-1][j] = matrix[m-1][j];
//         }
//         for(int i=m-2;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 int down = matrix[i][j] +  f(i+1,j,matrix,dp);
//                 int left = matrix[i][j]; 
//                 if(j-1>=0)
//                 left+=f(i+1,j-1,matrix,dp);
//                 else
//                 left+=1e9;
//                 int right = matrix[i][j];
//                 if(j+1<n) 
//                 right+=f(i+1,j+1,matrix,dp);
//                 else right+=1e9;

//                 dp[i][j] = min({down,left,right});
//             }
//         }
        
//         for(auto it:dp[0])
//         ans = min(ans,it);

//         return ans;
//     }
// };

class Solution {
public:
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0 || j<0|| j>=matrix.size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left =f(i-1,j-1,matrix,dp) + matrix[i][j];
        int up = f(i-1,j,matrix,dp) + matrix[i][j];
        int right = f(i-1,j+1,matrix,dp)  + matrix[i][j];
        return dp[i][j]=min({left,up,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,0));
        /* for(int j=0;j<n;j++){
            ans = min(ans,f(m-1,j,matrix,dp));
        } */
        //return ans;
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
           
                int left = matrix[i][j];
                if(i-1>=0 && j-1>=0) left+=dp[i-1][j-1];
                else left+=1e9;
                int up =  matrix[i][j];
                up+=dp[i-1][j];
                
                 int right =  matrix[i][j];
                 if(i-1>=0 && j+1<n) right+=dp[i-1][j+1];
                 else right+=1e9;
                 dp[i][j] = min({left,right,up});
            }
        }
        for(int j=0;j<n;j++){
            ans = min(ans,dp[m-1][j]);
        }
        return ans;
    }
};