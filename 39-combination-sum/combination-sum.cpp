class Solution {
public:
    void generate(int ind, int target, vector<int>&v, vector<vector<int>>&ans, vector<int>&candidates){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(ind == candidates.size()){
            return;
        }
        if(candidates[ind]<=target){
        v.push_back(candidates[ind]);
        generate(ind,target-candidates[ind],v,ans,candidates);
        v.pop_back();
        }
        int j=ind+1;
        for( ;j<candidates.size();j++){
            if(candidates[j]!=candidates[j-1])
            break;
        }
        generate(j,target,v,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        generate(0,target,v,ans,candidates);
        return ans;
    }
};