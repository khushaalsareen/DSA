class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        if(m.find(x)==m.end()){
            vector<int>v(queries.size(),-1);
            return v;
        };
        auto it = m.find(x);
        int k = 0;
        for(int i=0;i<queries.size();i++){
            if(queries[i]>it->second.size())
            ans.push_back(-1);
            else
            ans.push_back(it->second[queries[i]-1]);
        }
        return ans;
    }
};