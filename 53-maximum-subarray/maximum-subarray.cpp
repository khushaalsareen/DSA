class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            //maximum sum suvarray ending at index i
            int val = max(nums[i],dp[i-1]+nums[i]);
            dp[i] = val;
        }
        return *max_element(dp.begin(),dp.end());
    }
};