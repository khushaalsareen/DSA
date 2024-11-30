class Solution {
public:
    void dfs(int node, vector<int>&ans,unordered_map<int,vector<int>>&adj){
        while(adj[node].size() > 0){
            int nextNode = adj[node].back();
            adj[node].pop_back();
            dfs(nextNode,ans,adj);
        }
        ans.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for (auto it : pairs) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        int startNode = pairs[0][0]; // why initialised to this beacuse if euler
                                     // path exists then start from any node
        for(auto it:adj){
            int ind = indegree[it.first];
            int oud = outdegree[it.first];
            if(oud - ind == 1)
            {
                startNode = it.first;
                break;
            }
        }
        vector<int>ans;
        dfs(startNode,ans,adj);
        reverse(ans.begin(),ans.end());
        vector<vector<int>>v;
        for(int i=0;i<ans.size()-1;i++){
            v.push_back({ans[i],ans[i+1]});
        }
        return v;
    }
};