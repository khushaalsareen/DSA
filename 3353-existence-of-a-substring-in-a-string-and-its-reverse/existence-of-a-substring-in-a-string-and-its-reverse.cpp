class Solution {
public:
bool isPalindrome(string &s,int st,int e){
        int i = st, j = e;
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    bool isSubstringPresent(string s) {
        if(s.size()<2) return false;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(isPalindrome(s,i,j))
                return true;
            }
        }
        return false;
       
    }
};