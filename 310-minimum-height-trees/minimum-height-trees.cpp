class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n == 1)
        return {0};
        vector<int>adjLs[n];
        vector<int>indegree(n,0);
        for(auto it:edges){
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        queue<int>q;
        // vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==1)
            {
                q.push(i);
                
                indegree[i]--;
            }
        }
        int rem = n;
        
        while(rem>2){
            int sz = q.size();
            rem-=sz;
            while(sz--){
                int currNode = q.front();
                q.pop();
                for(auto it:adjLs[currNode]){
                    indegree[it]--;
                    if(indegree[it]==1)
                    q.push(it);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};