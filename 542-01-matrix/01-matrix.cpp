class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>&visited, int m, int n,vector<vector<int>>&ans){
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                {q.push({0,{i,j}});
                visited[i][j] = 1;}
            }
        }
        while(!q.empty()){
            pair<int,pair<int,int>> p= q.front();
            q.pop();
            int currDist = p.first;
            int x = p.second.first;
            int y = p.second.second;
            ans[x][y] = currDist;

            for(int dx = -1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(abs(dx)==abs(dy)) continue;
                    int newX = x + dx;
                    int newY = y + dy;
                    if(newX>=0 && newY>=0 && newX<m && newY<n && mat[newX][newY]==1 && visited[newX][newY]==0){
                       q.push({currDist+1,{newX,newY}});
                       visited[newX][newY] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));
        bfs(mat,visited,m,n,ans);
        return ans;
    }
};