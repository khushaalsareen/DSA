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
    
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        int ans = -1e9;
       
        prev[0] = -1e9;
        prev[1] = -1e9;
        for(int ind =1;ind<=n;ind++){
            for(int k = 0;k<=1;k++){
                int notDelete = max(nums[ind-1],nums[ind-1]+prev[k]);
                int del = -1e9;
                if(k!=0)
                    del =  prev[k-1];
                curr[k] = max(del,notDelete);
                ans = max(ans,curr[k]);
            }
            prev = curr;
        }
        return ans;
    }
};