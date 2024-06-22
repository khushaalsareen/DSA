class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 1;
        int maxLen = 0;
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++; // include character ending at index j
            while(m[s[j]]>1){
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};