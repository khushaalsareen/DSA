class Solution {
public:
    vector<int> getRow(int r) {
        vector<vector<int>>dp;
        dp.push_back({1});
        for(int i=1;i<=r;i++){
            vector<int>v(i+1);
            v[0] = 1;
            v[i] = 1;
            for(int j=1;j<i;j++){
                v[j] = dp[i-1][j] + dp[i-1][j-1];
            }
            dp.push_back(v);
        }
        return dp[r];
    }
};