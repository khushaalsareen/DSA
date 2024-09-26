class Solution {
public:
    void f(int ind, vector<int>&v, vector<vector<int>> &ans,vector<int>nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=ind;j<nums.size();j++){
            swap(nums[ind],nums[j]);
            f(ind+1,v,ans,nums);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        f(0,v,ans,nums);
        return ans;
    }
};