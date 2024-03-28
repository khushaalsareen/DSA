class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
        return "";
        int cnt = 0;
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int i = 0;
        int j = 0;
        int sp = -1;
        int ep = -1;
        string ans = "";
        int minLen = INT_MAX;
        unordered_map<char,int>m2;
        while(j<s.size()){
            
            m2[s[j]]++; // substrig ending at index j
            if(m.find(s[j])!=m.end() && m2[s[j]]<=m[s[j]])
            cnt++;
            

            while(cnt==t.size()){
                if(j-i+1<minLen){
                    minLen = j-i+1;
                   sp = i;
                   ep = j;
                }
                m2[s[i]]--;
                if(m2[s[i]]==0)
                m2.erase(s[i]);
                if(m.find(s[i])!=m.end() && m2[s[i]]<m[s[i]])
                cnt--;
                i++;
            }

            j++;
        }
        return sp!=-1 && ep!=-1 ? s.substr(sp,ep-sp+1):"";
    }
};