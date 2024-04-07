class Solution {
public:
    bool f(int idx, int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) 
        return true;
        if(idx==0)
        return arr[0]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notpick = f(idx-1,target,arr,dp);
        bool pick = false;
        if(arr[idx]<=target)
        pick = f(idx-1,target-arr[idx],arr,dp);
        return dp[idx][target] = pick || notpick;
    }
    bool canPartition(vector<int>& arr) {
        int t = 0;
        for(auto it: arr) t+=it;
        if(t%2) return false;
        vector<vector<int>>dp(arr.size(),vector<int>(t/2+1,-1));
        return f(arr.size()-1,t/2,arr,dp);
    }
};