class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        if(nums[0]==0)
        dp[0] = 0;
        if(nums[0]==1)
        dp[0] = 1;
        int maxLen = dp[0];
        for(int i=1;i<n;i++){
            if(nums[i]==0)
            dp[i] = 0;
            else
            dp[i] = 1 + dp[i-1];
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
};