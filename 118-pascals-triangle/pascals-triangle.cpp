class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i=1;i<n;i++){
            vector<int>v(i+1);
            v[0] = 1;
            for(int j=1;j<=i-1;j++){
                v[j] = dp[i-1][j] + dp[i-1][j-1];
            }
            v[i] = 1;
            dp.push_back(v);
        }
        return dp;
    }
};