class Solution {
public:
    int f(int val, vector<pair<int,vector<int>>>&v){
        int n = v.size();
        int l = 0;
        int h = n-1;
        int mid;
        int ans = -1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(v[mid].second[0]>=val){
                ans = v[mid].first;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    bool static cmp(pair<int,vector<int>>&p1, pair<int,vector<int>>&p2){
        return p1.second[0]<p2.second[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,vector<int>>>v;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            v.push_back({i,{intervals[i][0],intervals[i][1]}});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int currStart = v[i].second[0];
            int currEnd = v[i].second[1];
            int idx = f(currEnd,v);
            if(idx!=-1)
            ans[v[i].first]  = idx;
        }
        return ans;
    }
};