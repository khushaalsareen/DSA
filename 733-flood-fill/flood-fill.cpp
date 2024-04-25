class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>&image, vector<vector<int>>&visited, int color, int org){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]==1;
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for(int dx = -1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(abs(dx)==abs(dy)) continue;
                    int newX = p.first + dx;
                    int newY = p.second + dy;
                    if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size() && image[newX][newY]==org && visited[newX][newY]==0)
                    {
                        q.push({newX,newY});
                        visited[newX][newY] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        bfs(sr,sc,image,visited,color,org);
        return image;
    }
};