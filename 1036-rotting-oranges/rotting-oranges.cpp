class Solution {
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int bfs(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int currX = p.first.first;
            int currY = p.first.second;
            int currTime = p.second;
            time = currTime;
            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX>=0 && newY>=0 && newX<m && newY<n && !visited[newX][newY] && grid[newX][newY]==1){
                    q.push({{newX,newY},currTime+1});
                    visited[newX][newY] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !visited[i][j])
                return -1;
            }
        }
        return time;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};