class Solution {
public:
    int f(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){
        // there are no more cuts to consider
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int minCost = INT_MAX;
        for(int ind = i;ind<=j;ind++){
            // make cut at index ind
            int cost = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            minCost = min(cost,minCost);
        }    
        return dp[i][j] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts,dp);
    }
};