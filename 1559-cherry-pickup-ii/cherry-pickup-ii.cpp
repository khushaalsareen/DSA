class Solution {
public:
    int f(int i,int j1, int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp ){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
        return -1e9;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans = -1e9;
        for(int d1 = -1;d1<=1;d1++){
            for(int d2 = -1;d2<=1;d2++){
                if(j1==j2)
                ans = max(ans,grid[i][j1] + f(i+1,j1+d1,j2+d2,grid,dp));
                else
                ans = max(ans,grid[i][j1] + grid[i][j2] + f(i+1,j1+d1,j2+d2,grid,dp)); 
            }
        }
        return dp[i][j1][j2]= ans;
    } 
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,grid,dp);
    }
};