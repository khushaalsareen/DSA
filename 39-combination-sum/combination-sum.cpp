class Solution {
public:
    void generate(vector<vector<int>>&ans, vector<int>&v,vector<int>& candidates, int ind, int target){
       if(target<0)
       return;
       if(ind == candidates.size()){
        if(target == 0){
            ans.push_back(v);
        }
        return;
       }

        v.push_back(candidates[ind]);
        generate(ans,v,candidates,ind,target-candidates[ind]);
        v.pop_back();
        generate(ans,v,candidates,ind+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        generate(ans,v,candidates,0,target);
        return ans;
    }
};