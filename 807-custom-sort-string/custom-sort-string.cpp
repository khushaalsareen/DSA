class Solution {
public:
   static bool cmp(pair<char,int>p1,pair<char,int>p2){
       return p1.second<p2.second;
   }
    string customSortString(string order, string s) {
        unordered_map<char,int>m;
        for(int i=0;i<order.size();i++){
            m.insert({order[i],i});
        }
        vector<pair<char,int>>v;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end())
            v.push_back({s[i],27});
            else{
                v.push_back({s[i],m[s[i]]});
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            s[i] = v[i].first;
        }
        return s;
    }
};