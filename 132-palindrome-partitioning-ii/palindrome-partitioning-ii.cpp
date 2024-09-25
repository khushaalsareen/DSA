class Solution {
public:
    bool isPalindrome(int st, int e, string &s){
        while(st<e){
            if(s[st]!=s[e])
            return false;
            st++;
            e--;
        }
        return true;
    }
    int f(int i, int j, string &s,vector<int>&dp){
        if(i>j)
        return 0;
         
        if(dp[i]!=-1)
        return dp[i];
        int ans = 1e9;
        for(int k=i;k<=j;k++){
            if(isPalindrome(i,k,s)){
                int cuts = 1 + f(k+1,j,s,dp);
                ans = min(ans,cuts);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n  = s.size();
    
        vector<int>dp(n+1,-1);
        return f(0,n-1,s,dp)-1;
    }
};