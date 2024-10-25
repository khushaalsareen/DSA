class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        int n = nums.size();
        int ts = 1<<n;
        for(int mask = 0; mask<ts;mask++){
            vector<int>v;
            for(int bitPos = 0;bitPos<n;bitPos++){
                if(mask & (1<<bitPos)){
                    v.push_back(nums[n-1-bitPos]);
                }
            }
            if(s.find(v)==s.end()){
                ans.push_back(v);
                s.insert(v);
            }
        }
        return ans;
    }
};