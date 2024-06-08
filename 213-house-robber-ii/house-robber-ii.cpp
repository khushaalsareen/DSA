class Solution {
public:
    int f(int idx, vector<int>&nums, vector<int>&dp){
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
        vector<int>nums1,nums2;
        if(n==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0)
            nums2.push_back(nums[i]);
            if(i!=n-1)
            nums1.push_back(nums[i]);
        }
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        int amt1 = f(nums1.size()-1,nums1,dp1);
        int amt2 = f(nums2.size()-1,nums2,dp2);
        return max(amt1,amt2);
    }
};