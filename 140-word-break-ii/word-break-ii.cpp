class Solution {
public:
    void generate(int ind, string &s,unordered_map<string,int>&m,string &temp,vector<string>&ans){
        if(ind>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=ind;j<s.size();j++){
            string str = s.substr(ind,j-ind+1);
            if(m.find(str)!=m.end()){
                if(temp.size()==0)
               { temp+=str;
                generate(j+1,s,m,temp,ans);
                temp.erase(temp.end()-str.size(),temp.end());}
                else{
                temp=temp + " " + str;
                generate(j+1,s,m,temp,ans);
                string space = " ";
                temp.erase(temp.end()-str.size()- space.size(),temp.end());  
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string temp="";
        unordered_map<string,int>m;
        for(auto &it:wordDict){
            m[it]++;
        }
        generate(0,s,m,temp,ans);
        return ans;
    }
};