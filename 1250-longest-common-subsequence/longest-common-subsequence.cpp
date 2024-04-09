class Solution {
public:
    int f(int ind1, int ind2,string &text1, string &text2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1+1][ind2+1]!=-1) return dp[ind1+1][ind2+1];
        if(text1[ind1]==text2[ind2])
        return dp[ind1+1][ind2+1] = 1 + f(ind1-1,ind2-1,text1,text2,dp);
        else
        return dp[ind1+1][ind2+1] = max(f(ind1,ind2-1,text1,text2,dp),f(ind1-1,ind2,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n-1,m-1,text1,text2,dp);
         for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
         for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

        for(int ind1 =0;ind1<n;ind1++){
            for(int ind2=0;ind2<m;ind2++){
                 if(text1[ind1]==text2[ind2])
                 dp[ind1+1][ind2+1] = 1 + dp[ind1][ind2];
                 else
                dp[ind1+1][ind2+1] = max(dp[ind1+1][ind2],dp[ind1][ind2+1]);
            }
        }
        return dp[n][m];
    }
};