class Solution {
public:
    int f(int idx,vector<int>&dp){
        if(idx==0) return 1;
        if(idx<0) return 0; 
        if(dp[idx]!=-1) return dp[idx];
        int oneStep = f(idx-1,dp); // number of ways to reach from idx-1th stair to 0th stair
        int twoStep = f(idx-2,dp); // number of ways to reach from idx-2th stair to 0th stair
        return dp[idx] = 1*oneStep + 1*twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};