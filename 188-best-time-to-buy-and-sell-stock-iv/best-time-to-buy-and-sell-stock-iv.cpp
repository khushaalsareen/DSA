class Solution {
    int f(int ind, int buy,int k, vector<int>& nums ,vector<vector<vector<int>>>&dp){
    if(ind == nums.size())
    return 0;
    if(k==0)
    return 0;
    if(dp[ind][buy][k]!=-1)
    return dp[ind][buy][k];
    
    if(buy==0){
        int  notTake = f(ind+1,buy,k,nums,dp);
        int take = -nums[ind] + f(ind+1,1-buy,k,nums,dp);
        return dp[ind][buy][k] = max(take,notTake);
    }
    else{
        // wants to sell
        int notsell = f(ind+1,buy,k,nums,dp);
        int sell = nums[ind] + f(ind+1,1-buy,k-1,nums,dp);
        return dp[ind][buy][k] = max(sell,notsell);
    }
}
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,0,k,prices,dp);
    }
};