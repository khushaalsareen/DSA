class Solution {
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int sx = entrance[0];
        int sy = entrance[1];
        queue<pair<pair<int,int>,int>>q;
        q.push({{sx,sy},0});
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[sx][sy] = 1;
        vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int currX = p.first.first;
            int currY = p.first.second;
            int currDist = p.second;
            
            if(currDist>0 && (currX == 0 || currY == 0 || currX == m-1 || currY == n-1))
            return currDist;

            for(auto it:directions){
                int newX = currX + it.first;
                int newY = currY + it.second;
                if(newX>=0 && newY>=0 && newX < m && newY<n && visited[newX][newY]==0 && maze[newX][newY]=='.'){
                    q.push({{newX,newY},currDist+1});
                    visited[newX][newY] = 1;
                    
                }
            }
        }
        return -1;
    }
};