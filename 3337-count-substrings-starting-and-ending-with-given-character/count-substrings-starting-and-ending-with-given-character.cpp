class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        long long cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c)
            {cnt++;
            ans+=cnt;}
        }
        return ans;
    }
};