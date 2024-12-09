class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second<p2.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(auto it:intervals){
            v.push_back({it[0],it[1]});
        }
        sort(v.begin(),v.end(),cmp);
        int n = v.size();
        int cnt = 0;
        int et = -1e9;
        for(auto it:v){
            if(it.first>=et){
                cnt++;
                et = it.second;
            }
        }
        return n - cnt;
    }
};