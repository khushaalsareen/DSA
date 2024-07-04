class Solution {
public:
    void dfs(int src, vector<int>&visited, vector<int>&color, vector<vector<int>>&adj, int col,bool &ans){
        visited[src] = 1;
        color[src] = col;

        for(int i=0;i<adj[src].size();i++){
            if(!visited[adj[src][i]])
            dfs(adj[src][i],visited,color,adj,1-col,ans);
            else{
                if(color[adj[src][i]]!=1-col)
                {ans = false;
                }
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>color(n,-1);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,color,graph,0,ans);
            }
        }
        return ans;
    }
};