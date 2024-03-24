class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0;
        int ans = INT_MIN;
        vector<int> freq(26,0);
        for(;j<s.size();j++){
            if(freq[s[j]-'a']>=2){
                ans = max(ans,j-i);
                while(i<j && freq[s[j]-'a']>=2){
                    freq[s[i]-'a']--;
                    i++;
                }
            }
            freq[s[j]-'a']++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};