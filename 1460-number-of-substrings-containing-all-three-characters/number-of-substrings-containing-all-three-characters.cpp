class Solution {
public:
    int f(string &s){
       long long int n = s.size();
        int k = 2;
        unordered_map<char,int>m;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(j<n){
            m[s[j]]++;
            while(m.size()>2){
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
       long long int tot1 = (n*1LL*(n+1))/2;
        return tot1 - f(s); 
    }
};