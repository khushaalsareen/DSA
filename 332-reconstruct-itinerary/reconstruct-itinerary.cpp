class Solution {
public:
    void dfs(string &src, unordered_map<string,vector<string>>&adj,vector<string>&ans){
        while(adj[src].size()>0){
            string &nextNode = adj[src].back();
            adj[src].pop_back();
            dfs(nextNode,adj,ans);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(auto it:tickets){
            string &u = it[0];
            string &v = it[1];
            adj[u].push_back(v);
        }
        for(auto &it:adj){
            sort(it.second.rbegin(),it.second.rend());
        }
        string startPoint = "JFK";
        vector<string>ans;
        dfs(startPoint,adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};