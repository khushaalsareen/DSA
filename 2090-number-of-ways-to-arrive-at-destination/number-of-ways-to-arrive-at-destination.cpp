class Solution {
    int m = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        // Build adjacency list
        for (auto &it : roads) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Distance array and ways array
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Min-Heap for Dijkstra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            

            for (auto &[ngbr, ew] : adj[currNode]) {
                long long newDist = currDist + ew;

                // Found a shorter path
                if (newDist < dist[ngbr]) {
                    dist[ngbr] = newDist;
                    ways[ngbr] = ways[currNode];  // Reset ways count for this node
                    pq.push({newDist, ngbr});
                }
                // Found another shortest path
                else if (newDist == dist[ngbr]) {
                    ways[ngbr] = (ways[ngbr]%m + ways[currNode]%m) % m;
                }
            }
        }

        return ways[n - 1]; // Number of ways to reach node n-1
    }
};
