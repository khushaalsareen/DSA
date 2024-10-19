class Solution {
public:
    vector<int> getRow(int r) {
        // vector<vector<int>>dp;
        vector<int>prev;
        prev.push_back(1);
        for(int i=1;i<=r;i++){
            vector<int>v(i+1);
            v[0] = 1;
            v[i] = 1;
            for(int j=1;j<i;j++){
                v[j] = prev[j] + prev[j-1];
            }
            prev = v;
        }
        return prev;
    }
};