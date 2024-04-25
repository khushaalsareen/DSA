class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>&visited,vector<pair<int,int>>&directions,int m,int n,vector<vector<char>>& board,bool flag){
        if(visited[i][j]==-1 || visited[i][j]==1)
        return;
       
       flag ? visited[i][j] = 1 : visited[i][j] = -1;
        
        for(int k=0;k<directions.size();k++){
            int dx = directions[k].first;
            int dy = directions[k].second;
            int newX = i + dx;
            int newY = j + dy;
            if(newX>=0 && newX<m && newY>=0 && newY<n && board[newX][newY]=='O' && visited[newX][newY]==0){
                dfs(newX,newY,visited,directions,m,n,board,flag);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
                dfs(0,i,visited,directions,m,n,board,false);
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O')
            dfs(m-1,i,visited,directions,m,n,board,false);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            dfs(i,0,visited,directions,m,n,board,false);
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O')
            dfs(i,n-1,visited,directions,m,n,board,false);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    dfs(i,j,visited,directions,m,n,board,true);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==1)
                board[i][j] = 'X';
            }
        }
        
    }
};