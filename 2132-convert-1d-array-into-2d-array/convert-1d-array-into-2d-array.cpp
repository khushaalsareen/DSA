class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        int sz = nums.size();
        if(m*1LL*n != sz)
        return {};
        vector<vector<int>> ans(m,vector<int>(n));
        int idx =0 ;
        for(int i = 0;i<m;i++){
            for(int j  = 0;j<n;j++){
                ans[i][j] = nums[idx++];
            }
        }
        return ans;
    }
};