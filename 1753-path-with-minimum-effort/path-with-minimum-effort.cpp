class Solution {
public:
    void dijkstra(vector<vector<int>>& heights, vector<vector<int>>&dist,vector<pair<int,int>>&directions){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int currEffort = p.first;
            int currX = p.second.first;
            int currY = p.second.second;
            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX<0 || newY<0 || newX>=heights.size() || newY>=heights[0].size())
                continue;
                int edgeWeight = abs(heights[newX][newY] - heights[currX][currY]);
                int updatedEffort = max(edgeWeight, currEffort);
                if(updatedEffort<dist[newX][newY]){
                    dist[newX][newY] = updatedEffort;
                    pq.push({updatedEffort,{newX,newY}});
                }
            }
        }
        // return dist;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),1e9));
        vector<pair<int,int>>directions = {{0,1},{0,-1},{-1,0},{1,0}};
        dijkstra(heights,dist,directions);
        return dist[heights.size()-1][heights[0].size()-1]; 
    }
};