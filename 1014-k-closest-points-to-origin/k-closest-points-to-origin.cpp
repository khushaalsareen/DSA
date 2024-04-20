class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&p1, pair<int,int>&p2){
            return p1.first*p1.first + p1.second*p1.second > p2.first*p2.first + p2.second*p2.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            v.push_back({x,y});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
    return ans;
    }
};