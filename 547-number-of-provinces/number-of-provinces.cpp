class Solution {
    void dfs(int src, vector<int>&visited, vector<int>adj[]){
        visited[src] = 1;
        for(auto it:adj[src]){
            if(!visited[it])
            dfs(it,visited,adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>adj[V+1];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cnt = 0;
        vector<int>visited(V+1,0);
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};