class Solution {
public:
    void dfs(int sx, int sy, vector<vector<int>>&visited, vector<vector<int>>& image, int tarColor, int expColor,vector<pair<int,int>>&directions){
        visited[sx][sy] = 1;
        image[sx][sy] = tarColor;
        for(int i=0;i<directions.size();i++){
            int newX = sx + directions[i].first;
            int newY = sy + directions[i].second;
            if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size() && visited[newX][newY]==0 && image[newX][newY]==expColor){
                dfs(newX,newY,visited,image,tarColor,expColor,directions);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int expColor = image[sr][sc];
        int tarColor = color;
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        dfs(sr,sc,visited,image,tarColor,expColor,directions);
        return image;
    }
};