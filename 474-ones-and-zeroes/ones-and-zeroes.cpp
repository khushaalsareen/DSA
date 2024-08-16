class Solution {
public:
    int f(int ind, int m, int n,vector<int>&ones,vector<int>&zeroes,vector<vector<vector<int>>>&dp){
        if(ind == 0){
            if(zeroes[0]<=m && ones[0]<=n)
            return 1;
            else
            return 0;
        }
        if(dp[ind][m][n]!=-1)
        return dp[ind][m][n];
        
        int notpick = f(ind-1,m,n,ones,zeroes,dp);
        int pick = -1e9;
        if(ones[ind]<=n && zeroes[ind]<=m)
         pick = 1 + f(ind-1,m-zeroes[ind],n-ones[ind],ones,zeroes,dp);
        return dp[ind][m][n]= max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int>ones(size,0);
        vector<int>zeroes(size,0);
        vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<size;i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1')
                ones[i]++;
                else
                zeroes[i]++;
            }
        }
        return f(size-1,m,n,ones,zeroes,dp);
    }
};