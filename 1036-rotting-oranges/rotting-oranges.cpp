class Solution {
public:
    int bfs( vector<vector<int>>&visited, vector<pair<int,int>>&directions,vector<vector<int>>&grid){
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int currX = p.first.first;
            int currY = p.first.second;
            int currTime = p.second;
            cnt  = currTime;
            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]==1 && !visited[newX][newY]){
                    visited[newX][newY] = 1;
                    q.push({{newX,newY},currTime+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                return -1;
            }
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        return bfs(visited,directions,grid);
    }
};