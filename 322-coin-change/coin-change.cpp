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
    int coinChange(vector<int>& coins, int Amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(Amount+1,-1));
        // int ans = f(n-1,amount,coins,dp);
        // return ans>=1e9?-1:ans;

        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i =0;i<=Amount;i++){
            dp[0][i] = i%coins[0] == 0? i/coins[0] : 1e9;
        }

        for(int idx =1;idx<n;idx++){
            for(int amount = 1;amount<=Amount;amount++){
                int notpick = 0 + dp[idx-1][amount];// f(idx-1,amount,coins,dp);
                int pick = INT_MAX;
                if(coins[idx]<=amount)
                pick = 1 + dp[idx][amount-coins[idx]];// f(idx,amount-coins[idx],coins,dp);

                dp[idx][amount] = min(pick,notpick);
            }
        }
        return dp[n-1][Amount]>=1e9 ? -1 : dp[n-1][Amount];
    }
};