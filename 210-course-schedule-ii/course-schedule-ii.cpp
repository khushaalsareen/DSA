class Solution {
public:
     vector<int> topoSort(int V, vector<int>adj[]){
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int cour1 = prerequisites[i][0];
            int cour2 = prerequisites[i][1];
            adj[cour2].push_back(cour1);
        }
        vector<int> ans = topoSort(numCourses,adj);
        if(ans.size()==numCourses)
        return ans;
        return {};
    }
};