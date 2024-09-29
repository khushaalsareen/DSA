class Solution {
public:
    void dfs(int node, vector<int>&visited, vector<int>adj[]){
        visited[node] = 1;
        for(auto it:adj[node]){
            if(!visited[it])
            dfs(it,visited,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] && i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
            vector<int>visited(n+1,0);
            for(int i=1;i<=n;i++){
                if(!visited[i])
                {
                    cnt++;
                    dfs(i,visited,adj);
                }
            }
        
        return cnt;
    }
};