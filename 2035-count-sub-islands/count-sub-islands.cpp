class Solution {
public:
    void dfs(int sx, int sy,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<pair<int,int>>&directions,vector<vector<int>>&visited,bool &ans){
        visited[sx][sy] = 1;
        int m = visited.size();
        int n = visited[0].size();
        if(grid1[sx][sy]==0)
        ans = false;
        for(int i=0;i<4;i++){
            int newX = sx + directions[i].first;
            int newY = sy + directions[i].second;
            if(newX>=0 && newY>=0 && newX<m && newY<n && visited[newX][newY] == 0 && grid2[newX][newY] == 1){
                dfs(newX,newY,grid1,grid2,directions,visited,ans);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<pair<int,int>>directions = {{0,1},{0,-1},{-1,0},{1,0}};
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && visited[i][j]==0){
                        bool ans  = true;
                        dfs(i,j,grid1,grid2,directions,visited,ans);
                        if(ans)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};