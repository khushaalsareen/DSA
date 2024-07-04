class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>&visited, vector<vector<int>>&ans,vector<pair<int,int>>&directions){
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)
               { q.push({{i,j},0});
                visited[i][j] = 1;}
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int>p = q.front();
            q.pop();
            int currX = p.first.first;
            int currY = p.first.second;
            int currDist = p.second;
            ans[currX][currY] = currDist;

            for(int i=0;i<directions.size();i++){
                int newX = currX + directions[i].first;
                int newY = currY + directions[i].second;
                if(newX>=0 && newY>=0 && newX<mat.size() && newY<mat[0].size() && visited[newX][newY]==0 && mat[newX][newY]==1){
                    visited[newX][newY] = 1;
                    q.push({{newX,newY},currDist + 1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size()));
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,-1},{0,1}};
        bfs(mat,visited,ans,directions);
        return ans;
    }
};