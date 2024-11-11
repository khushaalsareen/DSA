class Solution {
public:
    int f(int ind1, int ind2, string &s, string &t,vector<vector<int>>&dp){
        if(ind2<0)
        return 1;
        if(ind2>=0 && ind1<0)
        return 0;
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2] = f(ind1-1,ind2-1,s,t,dp) + f(ind1-1,ind2,s,t,dp);
        }
        else
            return dp[ind1][ind2] = f(ind1-1,ind2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        vector<vector<int>>dp(s1,vector<int>(s2,-1));
        return f(s.size()-1,t.size()-1,s,t,dp);
    }
};