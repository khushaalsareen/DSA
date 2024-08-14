class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int len = 0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j = i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;   
    }
};