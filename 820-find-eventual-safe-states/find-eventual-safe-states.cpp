class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdegree(n,0);
        int node = 0;
        for(auto &it:graph){
            int sz = it.size();
            outdegree[node]=(sz);
            node++;
        }
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }

        queue<int>q;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
                // visited[i] = 1;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // ans.push_back(node);
            for(auto it:adj[node]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    q.push(it);
                    // visited[it] = 1;
                }
            }
        }
      for(int i=0;i<n;i++){
        if(outdegree[i]==0)
        ans.push_back(i);
      }
        return ans;

    }
};