class Solution {
public:
    int bfs(vector<vector<int>>&visited , vector<vector<int>>&grid,vector<pair<int,int>> &directions){
        int m = grid.size();
        int ans = 0;
        int n = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                {q.push({0,{i,j}});
                visited[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int currTime = p.first;
            ans = currTime;
            int currX = p.second.first;
            int currY = p.second.second;
            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1 && !visited[newX][newY]){
                    visited[newX][newY]  = 1;
                    q.push({currTime+1,{newX,newY}});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                return -1;
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<pair<int,int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};
        return bfs(visited,grid,directions);
    }
};