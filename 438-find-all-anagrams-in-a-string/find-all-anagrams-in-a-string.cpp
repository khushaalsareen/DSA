class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int k = p.size();
        unordered_map<char,int>m1;
        for(int i=0;i<p.size();i++){
            m1[p[i]]++;
        }
        unordered_map<char,int>m2;
        for(int i=0;i<k;i++){
            m2[s[i]]++;
        }
        if(m1==m2)
        ans.push_back(0);
        for(int i=k;i<s.size();i++){
            m2[s[i]]++;
            m2[s[i-k]]--;
            if(m2[s[i-k]]==0)
            m2.erase(s[i-k]);
            if(m1==m2)
            ans.push_back(i-k+1);
        }
        return ans;
    }
};