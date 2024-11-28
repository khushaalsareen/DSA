class Solution {
public:
    int bfs(int sx, int sy, vector<pair<int,int>>&directions, vector<vector<int>>&grid,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,pair<int,int>>>q;
        q.push_front({0,{0,0}});
        visited[sx][sy] = 1;
        int ans = 1e9;
        while(!q.empty()){
            pair<int,pair<int,int>> p  = q.front();
            q.pop_front();
            int currX = p.second.first;
            int currY = p.second.second;
            int currObstacles = p.first;
            if(currX == m-1 && currY == n-1){
                ans = min(ans,currObstacles);
            }
            for(int i=0;i<4;i++){
                int newX = currX + directions[i].first;
                int newY = currY + directions[i].second;
                if(newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY]){
                    if(grid[newX][newY]==1){
                        q.push_back({currObstacles+1,{newX,newY}});
                        visited[newX][newY] = 1;
                    }
                    else{
                        q.push_front({currObstacles,{newX,newY}});
                        visited[newX][newY] = 1;
                    }
                }
            }
        }
        return ans;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>visited(n,vector<int>(m,0));
        return bfs(0,0,directions,grid,visited);
    }
};