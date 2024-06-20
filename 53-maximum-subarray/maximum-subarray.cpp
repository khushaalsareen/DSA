class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // vector<int>dp(nums.size());
        int prev = nums[0];
        int maxi = prev;
        for(int i=1;i<nums.size();i++){
            int curr =max(nums[i],prev + nums[i]);
            maxi = max(maxi,curr);
            prev = curr;
        }
        return maxi;
    }
};