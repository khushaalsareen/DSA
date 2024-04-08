class Solution {
public:
    int f(int idx, int target, vector<int>& nums,vector<vector<int>>&dp) {
    if (idx == 0) {
        if(target==0 && nums[0]==0) return 2;
        return abs(target) == abs(nums[0]);
    }
    if(dp[idx][target+2000]!=-1) return dp[idx][target+2000];
    int plus = f(idx - 1, target - nums[idx], nums,dp);
    int minus = f(idx - 1, target + nums[idx], nums,dp);
    
    return dp[idx][target+2000]= plus + minus;
}

int findTargetSumWays(vector<int>& nums, int tar) {
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(4001,-1));
    return f(n - 1, tar, nums,dp);
}
};