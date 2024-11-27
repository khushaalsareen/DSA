class Solution {
public:
    int bfs(vector<int>adjLs[], int n){
        vector<int>visited(n,0);
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0] = 1;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int currNode = p.first;
            int currDist = p.second;
            if(currNode == n-1)
            return currDist;
            for(auto it:adjLs[currNode]){
                if(!visited[it]){
                    q.push({it,currDist+1});
                    visited[it] = 1;
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int>ans;
        vector<int>adjLs[n];
        for(int i=0;i<n-1;i++){
            adjLs[i].push_back(i+1);
        }
        for(int i=0;i<q;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adjLs[u].push_back(v);
            int dist = bfs(adjLs,n);
            ans.push_back(dist);
        }
        return ans;
    }
};