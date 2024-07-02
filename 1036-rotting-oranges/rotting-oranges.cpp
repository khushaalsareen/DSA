class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<pair<int,int>>&directions,vector<vector<int>>&visited){
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
               { q.push({0,{i,j}});
                 visited[i][j] = 1;
               }
            }
        }
        int ans = 0;
        while(!q.empty()){
          pair<int,pair<int,int>>p = q.front();
          q.pop();
          int currTime = p.first;
          int currX = p.second.first;
          int currY = p.second.second;
          ans = currTime;
          for(int i=0;i<directions.size();i++){
            int newX = currX + directions[i].first;
            int newY = currY + directions[i].second;
            if(newX>=0 && newY>=0 && newX<grid.size() && newY<grid[0].size() && visited[newX][newY]==0 && grid[newX][newY]==1){
                visited[newX][newY] = 1;
                q.push({currTime+1,{newX,newY}});
            }
          }  
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                return -1;
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>>visited(m,vector<int>(n,0));
        return bfs(grid,directions,visited);
    }
};