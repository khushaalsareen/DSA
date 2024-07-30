class Solution {
public:
    void generate(int ind,vector<int>&v, vector<int>& candidates, int target, vector<vector<int>> &ans ){
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        if(ind == candidates.size()){
            if(target == 0)
            ans.push_back(v);
            return;
        }
       
        if(candidates[ind]<=target)
       { v.push_back(candidates[ind]);
        generate(ind,v,candidates,target-candidates[ind],ans);
        v.pop_back();}

         generate(ind+1,v,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        generate(0,v,candidates,target,ans);
        return ans;
    }
};