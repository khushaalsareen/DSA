class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        m[s[i]]++;
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end())
            return t[i];
            else
           { m[t[i]]--;
             if(m[t[i]]==0)
             m.erase(t[i]);
           }
        }
        for(auto it:m){
            int ch = it.first;
            int fq = it.second;
            if(fq==1)
            return ch;
        }
        return 'a';
    }
};