class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string str1 = text1;
        string str2 = text2;
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));
        // return f(s1,s2,text1,text2,dp);
        for(int i=0;i<=s2;i++)
        dp[0][i] = 0;
        for(int i=0;i<=s1;i++)
        dp[i][0] = 0;
        for(int ind1=1;ind1<=s1;ind1++){
            for(int ind2=1;ind2<=s2;ind2++){
                if(str1[ind1-1]==str2[ind2-1])
       dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];// f(ind1-1,ind2-1,str1,str2,dp);
        else
         dp[ind1][ind2] = max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
            }
        }
        return dp[s1][s2];
    }
    int minInsertions(string s) {
        string revStr = s;
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        int len = longestCommonSubsequence(s,revStr);
        return s.size() - len;
    }
};