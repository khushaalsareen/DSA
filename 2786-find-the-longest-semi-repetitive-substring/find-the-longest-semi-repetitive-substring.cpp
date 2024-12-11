class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        int j = 1;
        int len = 1;
        while(j<n){
            if(s[j]==s[j-1])
            cnt++;
            while(cnt>1){
                if(s[i]==s[i+1])
                cnt--;
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};