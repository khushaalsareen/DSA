class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>adj[V];
         vector<int>outdegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }
       queue<int>q;
       for(int i=0;i<V;i++){
        if(outdegree[i]==0)
        q.push(i);
       }
       vector<int>safe(V,0);
       while(!q.empty()){
        int node = q.front();
        q.pop();
        safe[node] = 1;
        for(auto it:adj[node]){
            outdegree[it]--;
            if(outdegree[it]==0)
            q.push(it);
        }
       }
       vector<int>ans;
       for(int i=0;i<V;i++){
        if(safe[i])
        ans.push_back(i);
       }
       return ans;
    }
};