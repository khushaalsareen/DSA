class Solution {
public:
    int f(int idx, vector<int>&nums,vector<int>&dp){

        if(idx == 0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] ;
        if(idx>1) take+=f(idx-2,nums,dp);
        int notTake = 0 + f(idx-1,nums,dp);

        return dp[idx] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
    }
};