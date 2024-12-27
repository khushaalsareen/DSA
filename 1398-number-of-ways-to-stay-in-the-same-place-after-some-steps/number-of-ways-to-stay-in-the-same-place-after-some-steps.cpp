class Solution {
    int m = 1e9+7;
public:
    int f(int ind, int steps, int n,vector<vector<int>>&dp){
        if(ind<0 || ind>=n)
        return 0;
        if(steps == 0){
            if(ind == 0)
            return 1;
            else
            return 0;
        }
        if(dp[ind][steps]!=-1)
        return dp[ind][steps]%m;

        int left = f(ind-1,steps-1,n,dp)%m;
        int right = f(ind+1,steps-1,n,dp)%m;
        int curr = f(ind,steps-1,n,dp)%m;
        return dp[ind][steps] = ((left%m + right%m)%m + curr%m)%m;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(steps,vector<int>(steps+1,-1));
        return f(0,steps,arrLen,dp);
    }
};