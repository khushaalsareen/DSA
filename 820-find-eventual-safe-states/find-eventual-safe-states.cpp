class Solution {
public:
   vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<vector<int>> reverseGraph(graph.size()); // Reverse graph to store incoming edges
    vector<int> outDegree(graph.size()); // Out degree of each node
    
    // Construct reverse graph and compute out degrees
    for (int i = 0; i < graph.size(); ++i) {
        for (int j : graph[i]) {
            reverseGraph[j].push_back(i); // Add incoming edge
            outDegree[i]++; // Increment out degree
        }
    }
    
    queue<int> q;
    
    // Initialize queue with nodes having out degree 0 (safe nodes)
    for (int i = 0; i < graph.size(); ++i) {
        if (outDegree[i] == 0)
            q.push(i);
    }
    
    vector<int> result;
    
    // Perform BFS starting from nodes with out degree 0
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node); // Node is safe
        for (int neighbor : reverseGraph[node]) {
            outDegree[neighbor]--; // Decrement out degree of neighbors
            if (outDegree[neighbor] == 0)
                q.push(neighbor); // If out degree becomes 0, neighbor is safe
        }
    }
    
    sort(result.begin(), result.end()); // Sort the result
    return result;
}

};