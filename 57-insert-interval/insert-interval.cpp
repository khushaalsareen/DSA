class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& list) {
        vector<vector<int>>v;
        int i = 0;
        while(i<nums.size() && nums[i][1]<list[0]){
            v.push_back(nums[i]);
            i++;
        }
        
    
        v.push_back(list);

        while(i<nums.size()){
            //overlappibg
            if(v.back()[1]>=nums[i][0]){
                v.back()[0] = min(v.back()[0],nums[i][0]);
                v.back()[1] = max(v.back()[1],nums[i][1]);
            }
            else{
                v.push_back(nums[i]);
            }
            i++;
        }
        return v;
    }
};