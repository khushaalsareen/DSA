class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& list) {
        
        nums.push_back(list);
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        v.push_back({nums[0][0],nums[0][1]});
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]<=v.back()[1]){
                v.back()[0] = min(v.back()[0],nums[i][0]);
                v.back()[1] = max(v.back()[1],nums[i][1]);
            }
            else
                v.push_back(nums[i]);
        }
        return v;
    }
};