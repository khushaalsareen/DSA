class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long int,int>m;
        m[nums[0]] = 0;
        for(int i=1;i<nums.size();i++){
            if(m.find(target*1LL-nums[i])!=m.end()){
                auto it = m.find(target - nums[i]);
                return {i,it->second};
            }
            m[nums[i]*1LL]  = i;
        }
        return {};
    }
};