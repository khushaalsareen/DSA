class Solution {
public:
    bool isMatch(string s1, string s2) {
         int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // Initialize a DP table with -1 (uncomputed state)
    // return f(n - 1, m - 1, s1, s2, dp) ? 1 : 0;
    dp[0][0] = true;
    int j = 0;
    while(j<m && s2[j] == '*')
    {dp[0][j+1] = true;
    j++;}
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1] == s2[ind2-1] || s2[ind2-1] == '?') {
           dp[ind1][ind2] = dp[ind1-1][ind2-1];
    } else if(s2[ind2-1] == '*') {
        dp[ind1][ind2] = dp[ind1][ind2-1] || dp[ind1-1][ind2];// f(ind1 , ind2-1, s1, s2, dp) || f(ind1 - 1, ind2, s1, s2, dp);
    } else {
         dp[ind1][ind2] = false;
    }
        }
    }
    return dp[n][m];
    }
};