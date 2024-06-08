class Solution {
public:
    int f(int idx, vector<int>&nums,vector<int>&dp){
        if(idx==0)
          return nums[0];
        if(idx<0) 
          return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = f(idx-2,nums,dp) + nums[idx];
        int notTake = f(idx-1,nums,dp) + 0;
        return dp[idx] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,0);
        // return f(nums.size()-1,nums,dp);
        int prev1 = nums[0];
        int prev2 = 0;
        for(int idx=1;idx<n;idx++){
        int take = nums[idx];
        if(idx>=2)
        take += prev2;
        int notTake = prev1 + 0;
        int curr = max(take,notTake);
        prev2 = prev1;
        prev1 = curr;
        }
        return prev1;
    }
};