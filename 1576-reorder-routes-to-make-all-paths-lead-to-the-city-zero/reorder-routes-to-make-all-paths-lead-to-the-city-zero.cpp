class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& conn : connections) {
            int a = conn[0], b = conn[1];
            adj[a].push_back({b, 1});  // original direction a -> b (requires reorientation if used)
            adj[b].push_back({a, 0});  // reverse direction b -> a (no reorientation needed)
        }

        int ans = 0;
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto& neighbor : adj[city]) {
                int next_city = neighbor.first;
                int original_direction = neighbor.second;

                if (!visited[next_city]) {
                    visited[next_city] = 1;
                    if (original_direction == 1) {
                        ans++;  // This road needs to be reoriented to reach city 0
                    }
                    q.push(next_city);
                }
            }
        }

        return ans;
    }
};
