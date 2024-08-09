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
        vector<vector<int>>isPalindrome(n+1,vector<int>(n+1,true));
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                // if i--j is palindrome
                if(s[i]!=s[j])
                isPalindrome[i][j] = false;
                else{
                    isPalindrome[i][j] = isPalindrome[i+1][j-1];
                }
            }
        }
        dp[n] = 0;
        for(int ind = n-1;ind>=0;ind--){
            int minCost = 1e9;
        for(int j = ind;j<n;j++){
            if(isPalindrome[ind][j]){
            int cost = 1 + dp[j+1];
            minCost = min(cost,minCost);
            }
        }
         dp[ind]= minCost;
        }
        return dp[0]-1;
    }
};