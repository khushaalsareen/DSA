class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n==0)
        return 0;

        vector<int>dp(n);
        // dp[i] = longest valid parenthesis ending at index i
        dp[0] = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')
            dp[i] = 0;
            else{
                if(s[i-1]=='('){
                dp[i] = 2;
                if(i-2>=0)
                dp[i]+=dp[i-2];
                }
                else{
                    int ind = i - dp[i-1] - 1;
                    // ....((...))
                    if(ind>=0){
                    if(s[ind]==')')
                    dp[i] = 0;
                    else{
                        dp[i] = dp[i-1] + 2; 
                        if(ind-1>=0)
                        dp[i]+=dp[ind-1];
                    }
                }
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};