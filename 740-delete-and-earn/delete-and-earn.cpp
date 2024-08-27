class Solution {
public:
    int f(int ind, vector<int>&nums,vector<int>&dp){
        if(ind <= 0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int notPick = 0 + f(ind-1,nums,dp);
        int pick = -1e9;
        //  if(ind>1)
         pick = nums[ind] * ind + f(ind -2,nums,dp);
        return dp[ind] = max(pick,notPick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        if(nums.size()==1)
        return nums[0];
        for(auto it:nums){
            freq[it]++;
        }
        vector<int>dp(maxi+1,-1);
       return f(maxi,freq,dp);
    }
};