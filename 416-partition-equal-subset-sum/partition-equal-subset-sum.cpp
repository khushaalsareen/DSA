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
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=target)
        dp[0][nums[0]] = true;
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum/2;target++){
                bool notpick = dp[ind-1][target];// f(ind-1,target,nums,dp);
                bool pick = false;
                if(target>=nums[ind])
                pick = dp[ind-1][target-nums[ind]];// f(ind-1,target-nums[ind],nums,dp);
                dp[ind][target]= pick || notpick;
            }
        }
        return dp[n-1][target];
    }
};