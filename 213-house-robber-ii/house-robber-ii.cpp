class Solution {
public:
     int f(int ind, vector<int>&nums,vector<int>&dp){
        if(ind == 0)
        return nums[0];
        if(ind <0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int notPick = f(ind-1,nums,dp);
        int pick = nums[ind] + f(ind-2,nums,dp);
        return dp[ind] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp1,temp2;
        if(n==1)
        return nums[0];
        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(f(temp1.size()-1,temp1,dp1),f(temp2.size()-1,temp2,dp2));
    }
};