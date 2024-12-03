class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>rows(m,0);
        vector<int>cols(n,0);
        for(int i=0;i<m;i++){
            // processing current row
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                cnt++;
            }
            rows[i] = cnt;
        }
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)
                cnt++;
            }
            cols[j] = cnt;
        }
        int tot = 0;
        for(auto it:rows){
            if(it>1)
            tot+=it;
        }
        for(auto it:cols){
            if(it>1)
            tot+=it;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && rows[i]>1 && cols[j]>1){
                    tot-=1;
                }
            }
        }
        return tot;
    }
};