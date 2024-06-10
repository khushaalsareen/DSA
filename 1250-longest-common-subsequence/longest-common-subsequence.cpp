class Solution {
public:
    int f(int ind1, int ind2, string &text1, string &text2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0)
        return 0;
        if(dp[ind1+1][ind2+1]!=-1) return dp[ind1+1][ind2+1];
        if(text1[ind1]==text2[ind2])
        return 1 + f(ind1-1, ind2-1,text1,text2,dp);
        else
        return dp[ind1+1][ind2+1]= max(f(ind1-1,ind2,text1,text2,dp), f(ind1,ind2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size();
        int sz2 = text2.size();
        vector<vector<int>>dp(sz1+1,vector<int>(sz2+1,0));
        
        for(int i=0;i<text2.size();i++){
            dp[-1+1][i] = 0; 
        }
        for(int i=0;i<text1.size();i++){
            dp[i][-1+1] = 0;
        }
        for(int ind1 = 1;ind1<=text1.size();ind1++){
            for(int ind2 = 1; ind2<=text2.size(); ind2++){
                if(text1[ind1-1]==text2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];// f(ind1-1, ind2-1,text1,text2,dp);
                else dp[ind1][ind2]= max(dp[ind1][ind2-1], dp[ind1-1][ind2]);// f(ind1,ind2-1,text1,text2,dp));
            }
        }
        return dp[sz1][sz2];
    }
};