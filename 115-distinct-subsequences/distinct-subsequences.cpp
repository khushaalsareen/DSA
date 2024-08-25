class Solution {
    int f(int ind1, int ind2, string &s1, string &s2,vector<vector<int>>&dp){
    if(ind1<0 &&  ind2<0)
    return 1;
    if(ind2<0)
    return 1;
    if(ind1<0)
    return 0;
    if(dp[ind1][ind2]!=-1)
    return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2])
    return dp[ind1][ind2] = f(ind1-1,ind2-1,s1,s2,dp) + f(ind1-1,ind2,s1,s2,dp);
    else
    return dp[ind1][ind2] = f(ind1-1,ind2,s1,s2,dp); 
}
public:
    int numDistinct(string A, string B) {
          int n = A.size();
    int m = B.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,A,B,dp);
    }
};