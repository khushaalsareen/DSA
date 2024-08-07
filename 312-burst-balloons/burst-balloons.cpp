class Solution {
public:
    int f(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans = -1e9;
        for(int k=i;k<=j;k++){
            int score = nums[j+1]*nums[i-1]*nums[k] + f(i,k-1,nums,dp) + f(k+1,j,nums,dp);
            ans = max(ans,score);
        }
        return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};