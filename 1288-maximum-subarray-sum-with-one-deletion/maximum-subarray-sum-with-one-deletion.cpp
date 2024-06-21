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
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
        return arr[0];
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        int ans = -1e9;
        for(int i=0;i<n;i++){
            ans = max(ans,f(i,1,arr,dp));
        }
        return ans;
    }
};