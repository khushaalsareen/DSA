class Solution {
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int sx,int sy, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[sx][sy] = 1;
        board[sx][sy] = '@';
        for(auto it:directions){
            int newX = sx + it.first;
            int newY = sy + it.second;
            if(newX>=0 && newX<board.size() && newY>=0 && newY<board[0].size() && !visited[newX][newY] && board[newX][newY]=='O'){
                dfs(newX,newY,board,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        // first row
        int r = 0;
        for(int c = 0;c<n;c++){
            if(board[r][c]=='O' && !visited[r][c])
            dfs(r,c,board,visited);
        }
        // last row
        r = m-1;
        for(int c = 0;c<n;c++){
            if(!visited[r][c] && board[r][c]=='O')
                dfs(r,c,board,visited);
        }
        // first col
        int c = 0;
        for(int r = 0;r<m;r++){
            if(board[r][c]=='O' && !visited[r][c])
                dfs(r,c,board,visited);
        }
        // last col
        c = n-1;
        for(int r = 0;r<m;r++){
            if(!visited[r][c] && board[r][c]=='O')
                dfs(r,c,board,visited);
        }

        for(auto &it:board){
            for(auto &c:it){
                if(c=='O')
                    c = 'X';
            }
        }

        for(auto &it:board){
            for(auto &c:it){
                if(c=='@')
                    c = 'O';
            }
        }
    }
};