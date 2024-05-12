class Solution {
public:
    int f(int ind, int taken,vector<int>& energy, int k,vector<vector<int>>&dp){
        if(ind>=energy.size() && taken==0) return -1e9;
        if(ind>=energy.size()) return 0;
        if(dp[ind][taken]!=-1)
        return dp[ind][taken];
        int take = energy[ind] + f(ind+k,1,energy,k,dp);
        int nottake = INT_MIN;
        if(taken==0)
        nottake = 0 + f(ind+1,taken,energy,k,dp);
        return dp[ind][taken] =  max(take,nottake);
    }
    int maximumEnergy(vector<int>& energy, int k) {
     
        vector<vector<int>>dp(energy.size(),vector<int>(2,-1));
        return f(0,0,energy,k,dp);
    }
};