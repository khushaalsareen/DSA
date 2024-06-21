class Solution {
public:
    int f(int ind, int k,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0)
        return nums[0];

        if(dp[ind][k]!=-1) return dp[ind][k];
        int notDelete = max(nums[ind],nums[ind]+f(ind-1,k,nums,dp));
        int del = -1e9;
        if(k!=0)
         del =  f(ind-1,k-1,nums,dp);
        return dp[ind][k] = max(del,notDelete);
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        vector<vector<int>>dp(n,vector<int>(2,0));
        
        int ans = -1e9;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,f(i,1,arr,dp));
        // }
        // return ans;
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int ind =1;ind<n;ind++){
            for(int k = 0;k<=1;k++){
                int notDelete = max(nums[ind],nums[ind]+dp[ind-1][k]);
                int del = -1e9;
                if(k!=0)
                    del =  dp[ind-1][k-1];
                dp[ind][k] = max(del,notDelete);
                ans = max(ans,dp[ind][k]);
            }
        }
        return ans;
    }
};