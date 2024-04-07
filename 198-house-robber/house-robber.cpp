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
        vector<int>dp(nums.size(),0);
        // return f(nums.size()-1,nums,dp);
        dp[0] = nums[0];
        for(int idx=1;idx<nums.size();idx++){
        int take = nums[idx] ;
        if(idx>1) take+=dp[idx-2]; //f(idx-2,nums,dp);
        int notTake = 0 + dp[idx-1];// f(idx-1,nums,dp);

         dp[idx] = max(take,notTake);
        }
        return dp[nums.size()-1];
    }
};