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
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
       
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                int minCost = INT_MAX;
         for(int ind = i;ind<=j;ind++){
            // make cut at index ind
            int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
            minCost = min(cost,minCost);
        }    
        dp[i][j] = minCost;
            }
        }
        return dp[1][c];
    }
};