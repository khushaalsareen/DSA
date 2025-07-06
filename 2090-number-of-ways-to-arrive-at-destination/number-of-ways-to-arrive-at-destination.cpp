class Solution {
    const int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n, LLONG_MAX);
        vector<pair<int, int>> adj[n];
        vector<int> ways(n, 0);

        for (auto& it : roads) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].emplace_back(v, wt);
            adj[v].emplace_back(u, wt);
        }

        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            for (auto& [neighbor, wt] : adj[currNode]) {
                long long newDist = currDist + wt;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                    ways[neighbor] = ways[currNode];
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[currNode]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
