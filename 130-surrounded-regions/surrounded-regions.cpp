class Solution {
public:
    void dfs(int sx, int sy, vector<vector<char>>& board,vector<vector<int>>& visited,vector<pair<int,int>>&dir){
        visited[sx][sy] = 1;
        board[sx][sy] = 'a';
        for(int i=0;i<dir.size();i++){
            int newX = sx + dir[i].first;
            int newY = sy + dir[i].second;
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size() && visited[newX][newY]==0 && board[newX][newY]=='O'){
                dfs(newX,newY,board,visited,dir);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        vector<pair<int,int>>directions = {{0,1},{0,-1},{-1,0},{1,0}};
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O' && visited[0][i]==0)
            dfs(0,i,board,visited,directions);
        }
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O' && visited[board.size()-1][i]==0)
            dfs(board.size()-1,i,board,visited,directions);
        }
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O' && visited[i][0]==0)
            dfs(i,0,board,visited,directions);
        }
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O' && visited[i][board[0].size()-1]==0)
            dfs(i,board[0].size()-1,board,visited,directions);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                board[i][j]='X';
                if(board[i][j]=='a')
                board[i][j] = 'O';
            }
        }
        
    }
};