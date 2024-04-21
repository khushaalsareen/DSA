class Solution {
public:
    int count(int j, int val, vector<vector<int>>&grid,vector<vector<int>>&dp){
          int m = grid.size();
          int n = grid[0].size();
          if(j==n)
          return 0;
        
        if(dp[j][val+1]!=-1)
        return dp[j][val+1];
        
         unordered_map<int, int>m1;
         
         int i = 0;
         for(int i=0;i<10;i++)
         m1[i] = 0;

         for(int k=0;k<m;k++){
            m1[grid[k][j]]++;
         }
         int ans = 1e9;
         for(auto it = m1.begin();it!=m1.end();it++){
              int ops = count(j+1,it->first,grid,dp);
              if(it->first!=val)
                  ops+=m-it->second;
               else
                   ops+=m;
                
             ans = min(ans,ops);
              
         }
          
         return dp[j][val+1]= ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(11,-1));
       
        return count(0,-1,grid,dp);
    }
};