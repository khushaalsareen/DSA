class Solution {
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool dfs(int i, int j, vector<vector<char>>&board, string &word, int ind){
        if(ind+1 == word.size())
        return true;

        char ch = board[i][j];
        board[i][j] = '#';
        for(auto it:directions){
            int newX = i + it.first;
            int newY = j + it.second;
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size() && word[ind+1]==board[newX][newY]){
                if(dfs(newX,newY,board,word,ind+1))
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};