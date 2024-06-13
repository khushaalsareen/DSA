class Solution {
public:
    int f(int idx, string &s, unordered_map<char,int>&m1, unordered_map<int,char>&m2,vector<int>&dp){
        if(idx>=s.size()){
            return 1;
        }
        
        if(dp[idx]!=-1) return dp[idx];

        int one = 0;
        if(s[idx]!='0')
        one = f(idx+1,s,m1,m2,dp);
        int two = 0;
        if(idx+1<s.size() && s[idx]!='0' && m2.find(stoi(s.substr(idx,2)))!=m2.end())
        two = f(idx+2,s,m1,m2,dp);

        return dp[idx] = one + two;
    }
    int numDecodings(string s) {
        unordered_map<char,int>m1;
        unordered_map<int,char>m2;
        string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0;i<temp.size();i++){
            m1.insert({temp[i],temp[i]-'A'+1});
            m2.insert({temp[i]-'A'+1,temp[i]});
        }
 
        vector<int>dp(s.size(),-1);
        return f(0,s,m1,m2,dp);

    }
};