class Solution {
public:
    int f(int ind,vector<int>&dp){
        if(ind == 0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];

        int mini = 1e9;
        for(int i=1;i*i<=ind;i++){
            int coins = 1 + f(ind - i*i,dp);
            mini =  min(mini,coins);
        }
        return dp[ind] = mini;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};