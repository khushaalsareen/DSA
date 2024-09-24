class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        sort(strs.begin(),strs.end());
        string &s1 = strs[0];
        string &s2 = strs[strs.size()-1];
        int  i =0;
        while(i<s1.size()){
            if(s1[i]!=s2[i])
            break;
            else
            i++;
        }
        return s1.substr(0,i);
    }
};