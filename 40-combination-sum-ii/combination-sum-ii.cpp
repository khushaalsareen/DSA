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
        // take case
        if(candidates[ind]<=target)
       { v.push_back(candidates[ind]);
        generate(ind+1,v,candidates,target-candidates[ind],ans);
        v.pop_back();}
         // not take case
         // here u need to skip all further same elements
         int j;
         for( j = ind+1;j<candidates.size();){
            if(candidates[j]==candidates[ind])
            j++;
            else
            break;
         }
         generate(j,v,candidates,target,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        generate(0,v,candidates,target,ans);
        return ans;
    }
};