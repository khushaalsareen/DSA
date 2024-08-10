struct triplet{
    int stops;
    int val;
    int dist;
    triplet(){
        stops = 0;
        val = 0;
        dist = 0;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src] = 0;
        vector<pair<int,int>>adjLs[n];
        for(auto it:flights){
            adjLs[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q; // stops, node, dist
        q.push({0,{src,0}});
        while(!q.empty()){
            pair<int,pair<int,int>> p =q.front();
            q.pop();
            int currStops = p.first;
            int currNode = p.second.first;
            int currDist = p.second.second;
            for(auto it:adjLs[currNode]){
                int nextNode = it.first;
                int edgeWeight = it.second;
                if(nextNode == dst && currStops<=k){
                    if(currDist+edgeWeight<dist[nextNode]){
                    dist[nextNode] = currDist + edgeWeight;
                    q.push({currStops+1,{nextNode,dist[nextNode]}});
                    }
                }
                else if(nextNode!=dst && currStops<k){
                    if(currDist+edgeWeight<dist[nextNode]){
                    dist[nextNode] = currDist + edgeWeight;
                    q.push({currStops+1,{nextNode,dist[nextNode]}});
                    }
                }    
            }
        }
        return dist[dst] == 1e9? -1: dist[dst];
    }
};