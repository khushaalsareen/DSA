class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j =0 ;
        int n = s.size();
        unordered_map<char,int>m;
        int len = 0;
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>1){
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};