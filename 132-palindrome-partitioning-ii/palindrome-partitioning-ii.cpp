class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind, string &s, int n,vector<int>&dp){
        if(ind == s.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int minCost = 1e9;
        for(int j = ind;j<n;j++){
            if(isPalindrome(ind,j,s)){
            int cost = 1 + f(j+1,s,n,dp);
            minCost = min(cost,minCost);
            }
        }
        return dp[ind]= minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        // return f(0,s,n,dp)-1;
        dp[n] = 0;
        for(int ind = n-1;ind>=0;ind--){
            int minCost = 1e9;
        for(int j = ind;j<n;j++){
            if(isPalindrome(ind,j,s)){
            int cost = 1 + dp[j+1];
            minCost = min(cost,minCost);
            }
        }
         dp[ind]= minCost;
        }
        return dp[0]-1;
    }
};