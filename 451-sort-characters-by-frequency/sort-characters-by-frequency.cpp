class Solution {
public:
   static bool cmp(pair<char,int>&p1, pair<char,int>&p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        vector<pair<char,int>>v;
        for(auto it:m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v){
            int fq = it.second;
            while(fq--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};