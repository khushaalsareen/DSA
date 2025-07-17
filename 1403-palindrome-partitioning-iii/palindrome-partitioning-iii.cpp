class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind, int k, string &s, vector<vector<int>>&dp){
        if(ind == s.size()){
            if(k==0)
            return 0;
            else
            return 1e9;
        }

        if(k==1)
        {
            bool check = isPalindrome(ind,s.size()-1,s);
            if(check)
            return 0;
            else
            {
                int i = ind;
                int j = s.size() - 1;
                int tot = 0;
                while(i<j){
                    if(s[i]!=s[j])
                    tot++;
                    i++;
                    j--;
                }
                return tot;
            }
        }

        if(dp[ind][k]!=-1)
        return dp[ind][k];

        int ans = 1e9;
        for(int j = ind;j<s.size();j++){
            bool check = isPalindrome(ind,j,s);
            int curr = 0;
            if(check){
                curr =  0;
            }
            else{
                int i = ind;
                int k = j;
                int tot = 0;
                while(i<k){
                    if(s[i]!=s[k])
                    tot++;
                    i++;
                    k--;
                }
                curr = tot;
            }
            curr +=f(j+1,k-1,s,dp);
            ans  = min(ans,curr);
        }
        return dp[ind][k]= ans;
    }
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>>dp(s.size()+1,vector<int>(k+1,-1));
        return f(0,k,s,dp);
    }
};