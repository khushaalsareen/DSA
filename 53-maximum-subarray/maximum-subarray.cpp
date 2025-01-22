class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n);
        int prev = nums[0];
        // dp[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            //maximum sum suvarray ending at index i
            int val = max(nums[i],prev+nums[i]);
            int curr = val;
            ans = max(ans,curr);
            prev = curr;
        }
        return ans;
    }
};