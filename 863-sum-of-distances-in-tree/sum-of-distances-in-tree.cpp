class Solution {
public:
    int countNodes(int node, int prev, vector<int>adjLs[],vector<int>&freq){        
        int cnt = 0;
        cnt++;
        for(auto it:adjLs[node]){
            if(it!=prev){
                cnt+=countNodes(it,node,adjLs,freq);
            }
        }
        return freq[node] = cnt;
    }

    int findDistance(int node, vector<int>adjLs[]){
        queue<pair<pair<int,int>,int>>q;
        q.push({{node,-1},0});
        int cnt = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int currNode = p.first.first;
            int currParent = p.first.second;
            int currDist = p.second;
            cnt+=currDist;
            for(auto it:adjLs[currNode]){
                if(it!=currParent)
                q.push({{it,currNode},currDist+1});
            }
        }
        return cnt;
    }

    void evaluate(int node, int parent,vector<int>adjLs[],vector<int>&nodes,vector<int>&dp, int n){
        //processing current node
        if(node>0)
        dp[node] = dp[parent] - nodes[node] + n - nodes[node];
        for(auto it:adjLs[node]){
            if(it!=parent){
                evaluate(it,node,adjLs,nodes,dp,n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>freq(n);
        vector<int>adjLs[n];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        countNodes(0,-1,adjLs,freq);
        vector<int>dp(n);
        dp[0] = findDistance(0,adjLs); // distance of zero to each node
        evaluate(0,-1,adjLs,freq,dp,n);
        return dp;
    }
};