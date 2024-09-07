class Solution {
public:
    void f(int ind, vector<vector<int>>&ans, vector<int>&nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int j=ind;j<nums.size();j++){
            if(s.find(nums[j])!=s.end()) continue;
            s.insert(nums[j]); 
            swap(nums[ind],nums[j]);
            f(ind+1,ans,nums);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,ans,nums);
        return ans;
    }
};