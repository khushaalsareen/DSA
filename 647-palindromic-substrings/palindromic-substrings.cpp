class Solution {
public:
    
    bool f(int i, int j, string &s){
        if(i>=j)
        return true;
        if(s[i]!=s[j])
        return false;
        return f(i+1,j-1,s);
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                dp[i][j] = true;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                 if(s[i]!=s[j])
                dp[i][j] = false;
                else
                dp[i][j] =  dp[i+1][j-1];
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j])
                cnt++;
            }
        }
        return cnt;
    }
};