class Solution {
public:
    int f(int i, int j, int piles, vector<int>&stones,vector<int>&psum, int k,vector<vector<vector<int>>>&dp){

        if(i==j && piles == 1)
        return 0;
        if(i==j && piles>1)
        return 1e9;
        if(dp[i][j][piles]!=-1)
        return dp[i][j][piles];
        int ans = 1e9;
        if(piles == 1){
            return f(i,j,k,stones,psum,k,dp) + (i==0?psum[j]:psum[j] - psum[i-1]);
        }
        else{
            for(int t=i;t<j;t++){
                int cost = f(i,t,1,stones,psum,k,dp) + f(t+1,j,piles-1,stones,psum,k,dp);
                ans = min(ans,cost);
            }
        }
        return dp[i][j][piles] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int>psum(n,0);
        psum[0] = stones[0];
        for(int i=1;i<n;i++){
            psum[i] = psum[i-1] + stones[i];
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans =  f(0,n-1,1,stones,psum,k,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};