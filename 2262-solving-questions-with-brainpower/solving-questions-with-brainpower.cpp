class Solution {
public:
    long long f(int ind, vector<vector<int>>& questions,vector<long long int>&dp){
        if(ind>=questions.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];

        long long int solve = questions[ind][0] + f(ind+questions[ind][1]+1,questions,dp);
        long long int skip = f(ind+1,questions,dp);
        return dp[ind]= max(skip,solve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long int>dp(n,-1);
        return f(0,questions,dp);
    }
};