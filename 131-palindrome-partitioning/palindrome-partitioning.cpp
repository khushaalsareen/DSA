class Solution {
public:
    bool isPalindrome(string &temp){
        int i = 0;
        int j = temp.size()-1;
        while(i<j){
            if(temp[i++]!=temp[j--])
            return false;
        }
        return true;
    }
    void generate(int ind, vector<vector<string>>&ans, string &s, vector<string>&v){
        if(ind>=s.size()){
            ans.push_back(v);
            return;
        }
        for(int j=ind;j<s.size();j++){
            string temp = s.substr(ind,j-ind+1);
            if(isPalindrome(temp)){
                v.push_back(temp);
                generate(j+1,ans,s,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>v;
        generate(0,ans,s,v);
        return ans;
    }
};