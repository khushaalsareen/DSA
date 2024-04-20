class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq; // max heap
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            pq.push({d,{x,y}});
            if(pq.size()>k)
            pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};