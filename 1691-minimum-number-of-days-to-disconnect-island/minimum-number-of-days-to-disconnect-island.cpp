class Solution {
public:
    void dfs(int sx, int sy,vector<vector<int>>&visited,vector<vector<int>>&grid,vector<pair<int,int>>&directions){
        visited[sx][sy] = 1;
        for(int i=0;i<directions.size();i++){
            int newX = sx + directions[i].first;
            int newY = sy + directions[i].second;
            if(newX>=0 && newY>=0 && newX<grid.size() && newY<grid[0].size() && visited[newX][newY]==0 && grid[newX][newY]==1){
                dfs(newX,newY,visited,grid,directions);
            }
        }
    }
    int countIslands(vector<vector<int>>&grid){
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    cnt++;
                    dfs(i,j,visited,grid,directions);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = countIslands(grid);
        if(cnt>=2 || cnt == 0)
        return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    int val = countIslands(grid);
                    grid[i][j] = 1;
                    if(val>1 || val == 0)
                    return 1;
                }
            }
        }
        return 2;
    }
};