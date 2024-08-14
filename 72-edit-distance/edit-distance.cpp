class Solution {
public:
    int f(int ind1, int ind2, string &word1, string &word2,vector<vector<int>>&dp){
        if(ind1<0 && ind2<0)
        return 0;
        else if(ind1<0)
        return ind2+1;
        else if(ind2<0)
        return ind1+1;
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(word1[ind1] == word2[ind2])
        return dp[ind1][ind2] = f(ind1-1,ind2-1,word1,word2,dp);
        else{
            return dp[ind1][ind2] = 1 + min({f(ind1-1,ind2,word1,word2,dp),f(ind1,ind2-1,word1,word2,dp),f(ind1-1,ind2-1,word1,word2,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return f(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};