class Solution {
public:
    int f(int ind, int mod, vector<int>&nums,vector<vector<int>>&dp){
        if(ind == 0){
            if((nums[0]+mod)%3 == 0)
            return nums[0];
            else if(mod == 0)
            return 0;
            else
            return -1e9;
        }
        if(dp[ind][mod]!=-1)
        return dp[ind][mod];
        int take = nums[ind]+f(ind-1,(mod+nums[ind])%3,nums,dp);
        int notTake = f(ind-1,mod,nums,dp);
        return dp[ind][mod] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return max(f(n-1,0,nums,dp),0);
    }
};