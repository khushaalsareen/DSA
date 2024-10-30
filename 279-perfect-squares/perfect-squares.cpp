class Solution {
public:
    int f(int target,vector<int>&dp){
        if(target == 0)
        return 0;
        if(dp[target]!=-1)
        return dp[target];
        int mini = 1e9;
        for(int i=1;i*i<=target;i++){
            int coins = 1 + f(target-i*i,dp);
            mini = min(mini, coins);
        }
        return dp[target] = mini;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};