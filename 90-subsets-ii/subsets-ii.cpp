class Solution {
public:
    void generate(int &ind, vector<int>&v, vector<vector<int>>&ans, vector<int>&nums){
        if(ind == nums.size()){
            ans.push_back(v);
            return;
        }
        // take ith element
        v.push_back(nums[ind]);
        ind++;
        generate(ind,v,ans,nums);
        ind--;
        v.pop_back();
        // not take
        int j;
        for(j = ind+1;j<nums.size();j++){
            if(nums[j]!=nums[j-1])
            break;
        }
        generate(j,v,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        int ind = 0;
        generate(ind,v,ans,nums);
        return ans;
    }
};