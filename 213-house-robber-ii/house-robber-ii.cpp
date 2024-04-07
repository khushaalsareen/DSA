class Solution {
public:
int f(int ind,bool flag,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()) return 0;
        if(ind == nums.size()-1){
            return flag == true ? 0 : nums[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int take =0;
        if(ind==0) take = nums[ind] + f(ind+2,!flag,nums,dp);
        else take = nums[ind] + f(ind+2,flag,nums,dp);
 
        int nottake = f(ind+1,flag,nums,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        bool flag = false;
        vector<int>dp(nums.size(),-1);
        int ans=f(1,flag,nums,dp);
        fill(dp.begin(), dp.end(), -1);
        ans=max(ans,nums[0]+f(2,true,nums,dp));

        return ans;
    }
};