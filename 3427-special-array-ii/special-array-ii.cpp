class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> v;
        vector<int> psum(n, 0);

        // Build the prefix sum array
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                psum[i] = psum[i - 1] + 1;
            } else {
                psum[i] = psum[i - 1];
            }
        }
        for(auto it:psum){
            cout<<it<<" ";
        }
        // Process each query
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];

            int count =  psum[r] - psum[l];

            // A subarray is "special" if `count == 0` (no consecutive same-parity pairs)
            v.push_back(count == 0);
        }

        return v;
    }
};
