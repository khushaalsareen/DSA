class Solution {
public:
    bool f(int ind, int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)
        return true;
        if(ind == 0)
        return nums[ind] == target;
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        bool notpick = f(ind-1,target,nums,dp);
        bool pick = false;
        if(nums[ind]<=target)
        pick = f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]= pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
     int n = nums.size();
     int sum = 0;
     for(auto it:nums)
     sum+=it;
     if(sum%2 !=0)
     return false;
     int target = sum/2;
     vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
     return f(nums.size()-1,target,nums,dp);   
    }
};