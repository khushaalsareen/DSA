class Solution {
public:
    void dfs(int src, int visited[], vector<int>adjLs[], int V, int parent,int m,int &cnt, int &edge){
        visited[src] = 1;
        cnt++;
        for(auto it: adjLs[src]){
            edge++;
            if(!visited[it])
                {                
                dfs(it,visited,adjLs,V,src,m,cnt,edge);
            }
           
        }
        
    }
    int countCompleteComponents(int V, vector<vector<int>>& edges) {
        vector<int> adjLs[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        
        int visited[V];
        for(int i=0;i<V;i++)
            visited[i] = 0;
        
        int ans=0;
        for(int i=0;i<V;i++){
            int cnt =0;
            int edge =0;
            if(!visited[i]){
               dfs(i,visited,adjLs,V,-1,i,cnt,edge);
                if(edge==cnt*(cnt-1))
                    ans++;
            }
        }
        return ans;
    }
};