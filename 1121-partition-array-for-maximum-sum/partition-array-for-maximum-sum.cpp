class Solution {
public:
    int f(int s, int e, vector<int>&arr, int k,vector<int>&dp){
        if(s>e)
        return 0;
        if(dp[s]!=-1)
        return dp[s];
        int ans = 0;
        int maxi = 0;
        for(int ind = s;ind<s+k && ind<arr.size();ind++){
            maxi = max(maxi,arr[ind]);            
            int currSum = maxi*(ind-s+1) + f(ind+1,e,arr,k,dp);
            ans = max(ans, currSum);
        }
        return dp[s] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return f(0,n-1,arr,k,dp);
    }
};