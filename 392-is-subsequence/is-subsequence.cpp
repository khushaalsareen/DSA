class Solution {
public:
    bool isSubsequence(string str1, string str2) {
        int sz1 = str1.size();
    int sz2 = str2.size();
    vector<vector<int>>dp(sz1+1,vector<int>(sz2+1,0));
    for(int i = 0;i<=sz1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=sz2;i++){
        dp[0][i] = 0;
    }
    for(int ind1=1;ind1<=sz1;ind1++){
        for(int ind2=1;ind2<=sz2;ind2++){
            if(str1[ind1-1]==str2[ind2-1])
                 dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];// f(ind1-1, ind2-1,str1,str2,dp);
            else
                 dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);// f(ind1,ind2-1,str1,str2,dp));
        }
    }
    int len = dp[sz1][sz2];
    return len == str1.size();
    }
};