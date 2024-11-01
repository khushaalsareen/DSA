class Solution {
public:
    int f(int n, bool first,vector<vector<int>>&dp){
        if(n==0||n==1)
        return 1;
        if(dp[n][first]!=-1)
        return dp[n][first];
        int maxi = -1e9;
        for(int i=1;i<=n;i++){
            if (first){
                if(i==n) continue;
                else{
                    int curr = i * f(n - i,!first,dp);
            
                    maxi = max(maxi,curr);
                }
            }
            else{
                 int curr = i * f(n - i,first,dp);
            
                    maxi = max(maxi,curr);
            }
        
            
        }
        return dp[n][first] = maxi;
    }
    int integerBreak(int n) {
        bool var = true;
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(n,var,dp);
    }
};