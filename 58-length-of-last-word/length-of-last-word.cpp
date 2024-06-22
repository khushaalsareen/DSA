class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int j = n-1;
        while(s[j]==' ')
        j--;
        int i = j;
        while(j>=0 and s[j]!=' '){
            j--;
        }
        return i-j;
    }
};