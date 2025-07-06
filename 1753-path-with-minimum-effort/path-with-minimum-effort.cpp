class Solution {
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}}); // {dist,{x,y}}
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int currDist = p.first;
            int currX = p.second.first;
            int currY = p.second.second;
            
            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX>=0 && newY>=0 && newX<mat.size() && newY<mat[0].size()){
                    // cell is valid
                    int wt = abs(mat[currX][currY]-mat[newX][newY]);
                    if(dist[newX][newY]>max(currDist,wt)){
                        dist[newX][newY] = max(currDist,wt);
                        pq.push({dist[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};