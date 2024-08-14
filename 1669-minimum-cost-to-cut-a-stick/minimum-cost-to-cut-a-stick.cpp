class Solution {
public:
    int f(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        int minCost = 1e9;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        for(int k=i;k<=j;k++){
            int cost = cuts[j+1] - cuts[i-1] + f(k+1,j,cuts,dp) + f(i,k-1,cuts,dp);
            minCost = min(cost,minCost);
        }
        return dp[i][j]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return f(1,c,cuts,dp);
    }
};