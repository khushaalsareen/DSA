class Solution {
    int m = 1e9 + 7;
public:
    int f(int ind, int target, int k,vector<vector<int>>&dp){
       if(ind!=0 && target == 0)
       return 0;
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
    int numRollsToTarget(int n, int k, int Target) {
        if(Target>n*k)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(Target+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=Target;i++){
            dp[0][i] = 0;
        }
        for(int ind=1;ind<=n;ind++){
            for(int target=1;target<=Target;target++){
                 int cnt = 0;
        for(int i=1;i<=k;i++){
            int num = i;
            if(num<=target){
               cnt = (cnt + dp[ind-1][target-num])%m;// f(ind-1,target-num,k,dp))%m;
            }
            else
            break;
        }
         dp[ind][target] = cnt;
            }
        }
        return dp[n][Target];
        
    }
};