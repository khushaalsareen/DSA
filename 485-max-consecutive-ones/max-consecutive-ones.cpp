class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        if(nums[0]==0)
        dp[0] = 0;
        int ans = dp[0]==0?0:1;
        for(int i = 1;i<n;i++){
            if(nums[i] == 0)
            dp[i] = 0;
            else
            dp[i] = max(1 + dp[i-1],1);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};