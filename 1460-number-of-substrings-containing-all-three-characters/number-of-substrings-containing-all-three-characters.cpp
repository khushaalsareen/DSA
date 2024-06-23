class Solution {
public:
    int numberOfSubstrings(string s) {
     int n = s.size();
     int i = 0;
     int j = 0;
     int cnt = 0;
     unordered_map<char,int>m;
     while(j<n){
        m[s[j]]++;
        while(m.size()>2){
            m[s[i]]--;
            if(m[s[i]]==0)
            m.erase(s[i]);
            i++;
        }
        // map size is atmost 2
        cnt+=j-i+1;
        j++;
     } 
     return (n*1LL*(n+1))/2 - cnt;  
    }
};