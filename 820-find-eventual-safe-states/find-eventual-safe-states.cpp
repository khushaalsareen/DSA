class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>indegree(graph.size(),0);
        vector<int>adjLs[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[i]++;
                adjLs[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            ans.push_back(currNode);
            for(auto it:adjLs[currNode]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
            return ans;
    }
};