class Solution {
public:
    int f(int idx,vector<int>&dp){
        if(idx==0) return 1;
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = f(idx-1,dp);
        int two = f(idx-2,dp);
        return dp[idx] =  one + two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // return f(n,dp);
        dp[0] = 1;
        for(int idx=1;idx<=n;idx++){
             int one = dp[idx-1];// f(idx-1,dp);
             int two = 0;
             if(idx!=1)
              two = dp[idx-2];// f(idx-2,dp);
             dp[idx] =  one + two;
        }
        return dp[n];
    }
};