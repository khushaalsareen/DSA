class Solution {
public:
    int f(int idx, int amount , vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(idx==0){
            if(amount%coins[0] == 0)
            return amount/coins[0];
            else
            return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notpick = 0 + f(idx-1,amount,coins,dp);
        int pick = INT_MAX;
        if(coins[idx]<=amount)
        pick = 1 + f(idx,amount-coins[idx],coins,dp);

        return dp[idx][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        return ans>=1e9?-1:ans;
    }
};