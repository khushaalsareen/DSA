class Solution {
    int m = 1e9 + 7;
public:
    int f(int ind, int target, int k,vector<vector<int>>&dp){

        if(ind == 0){
            if(target == 0)
            return 1;
            else
            return 0;
        }
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        int cnt = 0;
        for(int i=1;i<=k;i++){
            int num = i;
            if(num<=target){
               cnt = (cnt + f(ind-1,target-num,k,dp))%m;
            }
            else
            break;
        }
        return dp[ind][target] = cnt;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(target>n*k)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,target,k,dp);
    }
};