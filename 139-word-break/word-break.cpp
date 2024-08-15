class Solution {
public:
    bool f(int i, int j, string &s, map<string,int>&mp,vector<int>&dp){
        if(i>j)
        return true;
        if(dp[i]!=-1)
        return dp[i];
        for(int k=i;k<=j;k++){
            int len = k-i+1;
            
            if(mp.find(s.substr(i,len))!=mp.end()){
                bool check = f(k+1,j,s,mp,dp);
                cout<<i<<" "<<check<<endl;
                if(check) return dp[i]= true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        if(mp.find(s)!=mp.end())
       { cout<<"burraj";
         return true;}
        vector<int>dp(s.size(),-1);
        return f(0,s.size()-1,s,mp,dp);
    }
};