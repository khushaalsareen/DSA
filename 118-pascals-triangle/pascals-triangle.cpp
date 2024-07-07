class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        
        for(int i = 1;i<=n;i++){
            vector<int>v(i);
            v[0] = 1;
            v[i-1] = 1;
            for(int j=1;j<i-1;j++){
                v[j] = ans[i-2][j] + ans[i-2][j-1];
            }
            ans[i-1]=v;
        }
        return ans;
    }
};