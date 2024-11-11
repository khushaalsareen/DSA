class Solution {
public:
    int f(int ind, int target, vector<vector<int>>&dp){
        if(target == 0)
        return 0;
        if(ind == 1)
        return target;
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        int nottake = f(ind-1,target,dp);
        int take = 1e9;
        if(ind*ind<=target)
         take = 1 + f(ind, target - ind*ind,dp);
        return dp[ind][target] = min(take,nottake);
    }
    int numSquares(int n) {
            int num = sqrt(n);
            if(num == 1)
            return n;
            vector<vector<int>>dp(num+1,vector<int>(n+1,-1));
            return f(num,n,dp);
    }
};