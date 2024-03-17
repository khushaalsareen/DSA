class Solution {
public:
    bool isSubstringPresent(string s) {
       if(s.size()==1)
       return false;

       for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])
        return true;
        int next = i==s.size()?-1: s[i+1];
        int prev = s[i-1];
        if(next==prev)
        return true;
       } 
       return false;
    }
};