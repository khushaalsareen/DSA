class Solution {
public:
    int f(int ind, string &s, vector<string>&dict,unordered_map<string,int>&m,vector<int>&dp){
        if(ind>=s.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int mini = s.size();
        for(int j=ind;j<s.size();j++){
            string temp = s.substr(ind,j-ind+1);
            int remExtra = f(j+1,s,dict,m,dp);
            if(m.find(temp)==m.end()){
                int curr = temp.size() + remExtra;
                mini = min(mini, curr);
            }
            else{
                mini = min(mini,remExtra);
            }
        }
        return dp[ind] = mini;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = dict.size();
        unordered_map<string,int>m;
        vector<int>dp(s.size()+1,-1);
        for(auto it:dict)
        m[it]++;
        return f(0,s,dict,m,dp);
    }
};