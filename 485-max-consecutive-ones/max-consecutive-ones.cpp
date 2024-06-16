class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int ans = 0;
        if(nums[0]==1)
        dp[0] = 1;
        ans = max(ans,dp[0]);
        for(int i = 1; i<nums.size();i++){
            if(nums[i]==1)
            dp[i] = 1 + dp[i-1];
            else
            dp[i] = 0;
            ans = max(ans,dp[i]);
        }
        return ans;
    }

};