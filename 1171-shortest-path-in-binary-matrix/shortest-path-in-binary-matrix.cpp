class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1)
        return -1;
        vector<vector<int>> visited(n,vector<int>(n,0));
        q.push({1,{0,0}});
        visited[0][0] = 1;
        pair<int,int> directions[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        while(!q.empty()){
            pair<int,pair<int,int>>p = q.front();
            q.pop();
            int currDist = p.first;
            int currX = p.second.first;
            int currY = p.second.second;
            if(currX==n-1 && currY == n-1)
                return currDist;
            for(int i=0;i<8;i++){
                int dx = directions[i].first;
                int dy = directions[i].second;
                int newX = currX + dx;
                int newY = currY + dy;
                if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0 && visited[newX][newY]==0){
                    q.push({currDist+1,{newX,newY}});
                    visited[newX][newY] = 1;
                }
            }
        }
        return -1;
    }
};

