class Solution {
public:
    void dfs(int sx, int sy, vector<vector<int>>& board,vector<vector<int>>& visited,vector<pair<int,int>>&dir){
        visited[sx][sy] = 1;
        board[sx][sy] = -1;
        for(int i=0;i<dir.size();i++){
            int newX = sx + dir[i].first;
            int newY = sy + dir[i].second;
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size() && visited[newX][newY]==0 && board[newX][newY]==1){
                dfs(newX,newY,board,visited,dir);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& board) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        vector<pair<int,int>>directions = {{0,1},{0,-1},{-1,0},{1,0}};
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]==1 && visited[0][i]==0)
            dfs(0,i,board,visited,directions);
        }
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]==1 && visited[board.size()-1][i]==0)
            dfs(board.size()-1,i,board,visited,directions);
        }
        for(int i=0;i<board.size();i++){
            if(board[i][0]==1 && visited[i][0]==0)
            dfs(i,0,board,visited,directions);
        }
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]==1 && visited[i][board[0].size()-1]==0)
            dfs(i,board[0].size()-1,board,visited,directions);
        }
        int cnt = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1)
               cnt++; 
            }
        }
        return cnt;
    }
};