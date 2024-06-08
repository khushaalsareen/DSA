class Solution {
public:
    int f(int ind, int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return nums[0] == target;
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        bool notpick = f(ind-1,target,nums,dp);
        bool pick = false;
        if(target>=nums[ind])
        pick = f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]= pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums)
        sum+=it;
        if(sum%2 == 1) return false;
        int target = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(nums.size()-1,target,nums,dp);
    }
};