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
     int tar = sum/2;
     vector<vector<int>>dp(nums.size(),vector<int>(tar+1,0));
    //  return f(nums.size()-1,target,nums,dp);   
    for(int ind =0;ind<n;ind++)
    dp[ind][0] = true;
    if(nums[0]==tar)
    dp[0][nums[0]] = true;
    for(int ind = 1;ind<n;ind++){
        for(int target = 1;target<=tar;target++){
            bool notpick = dp[ind-1][target];// f(ind-1,target,nums,dp);
        bool pick = false;
        if(nums[ind]<=target)
        pick = dp[ind-1][target-nums[ind]];// f(ind-1,target-nums[ind],nums,dp);
         dp[ind][target]= pick || notpick;
        }
    }
    return dp[n-1][tar];
    }
};