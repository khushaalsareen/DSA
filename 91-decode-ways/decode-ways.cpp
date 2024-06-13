class Solution {
public:
    int f(int idx, string &s, unordered_map<char,int>&m1, unordered_map<int,char>&m2,vector<int>&dp){
        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
        int cnt = 0;
        for(int i=idx;i<s.size();i++){
            if(m2.find(stoi(s.substr(idx,i-idx+1))) !=m2.end())
            {
                // stoi(s.substr(idx,i-idx+1))  ->> valid number that be be rep as character
                cnt+=f(i+1,s,m1,m2,dp);
            }
            else
            break;
        }
        return dp[idx] = cnt;
    }
    int numDecodings(string s) {
        unordered_map<char,int>m1;
        unordered_map<int,char>m2;
        string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0;i<temp.size();i++){
            m1.insert({temp[i],temp[i]-'A'+1});
            m2.insert({temp[i]-'A'+1,temp[i]});
        }
        if(s[0]=='0')
        return 0;
        vector<int>dp(s.size(),-1);
        return f(0,s,m1,m2,dp);
    }
};