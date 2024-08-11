class Solution {
public:
   bool dfs(set<pair<int,int>>& s, int wx, int wy, int x, int y, int target) {
    // If this state has been visited before, skip it
    if (s.find({wx, wy}) != s.end())
        return false;

    // If we've reached the target, return true
    if (wx == target || wy == target || wx + wy == target)
        return true;

    // Mark this state as visited
    s.insert({wx, wy});

    // Try all possible operations:

    // Fill jug x completely
    bool a1 = dfs(s, x, wy, x, y, target);
    if (a1) return true;

    // Fill jug y completely
    bool a2 = dfs(s, wx, y, x, y, target);
    if (a2) return true;

    // Empty jug x
    bool a3 = dfs(s, 0, wy, x, y, target);
    if (a3) return true;

    // Empty jug y
    bool a4 = dfs(s, wx, 0, x, y, target);
    if (a4) return true;

    // Transfer from x to y
    int pourXtoY = min(wx, y - wy); // Calculate the correct amount to transfer
    bool a5 = dfs(s, wx - pourXtoY, wy + pourXtoY, x, y, target);
    if (a5) return true;

    // Transfer from y to x
    int pourYtoX = min(wy, x - wx); // Calculate the correct amount to transfer
    bool a6 = dfs(s, wx + pourYtoX, wy - pourYtoX, x, y, target);
    if (a6) return true;

    return false; // No solution found for this state
}

bool canMeasureWater(int x, int y, int target) {
    if (target > x + y)
        return false;
    set<pair<int, int>> s;
    return dfs(s, 0, 0, x, y, target);
}

};