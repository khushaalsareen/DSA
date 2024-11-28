class Solution {
public:
    int f(int ind, int validTill,vector<int>& days, vector<int>& costs ,vector<vector<int>>&dp){
        if(ind>=days.size())
        return 0;
        if(dp[ind][validTill]!=-1)
        return dp[ind][validTill];
        if(days[ind]<=validTill)
        return dp[ind][validTill] = f(ind+1,validTill,days,costs,dp);
        int c0 = costs[0] + f(ind +1,days[ind],days,costs,dp);
        int c1 = costs[1] + f(ind+1,days[ind]+6,days,costs,dp);
        int c2 = costs[2] + f(ind+1,days[ind]+29,days,costs,dp);
        return dp[ind][validTill] = min({c1,c2,c0});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        int n = days.size();
        vector<vector<int>>dp(n,vector<int>(400,-1));
        return f(0,0,days,costs,dp);
    }
};