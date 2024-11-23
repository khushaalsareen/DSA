class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    // Transpose and reverse columns for 90° clockwise rotation
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][m - i - 1] = box[i][j];
        }
    }
    return ans;
}

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    // Step 1: Rotate the box 90° clockwise
    vector<vector<char>> ans = rotate(box);
    int m = ans.size();    // New number of rows
    int n = ans[0].size(); // New number of columns

    // Step 2: Simulate gravity in each column
    for (int j = 0; j < n; j++) { // For each column
        int emptyRow = m - 1; // The lowest available empty position
        for (int i = m - 1; i >= 0; i--) { // Traverse upwards in the column
            if (ans[i][j] == '*') { 
                // Obstacle found; reset emptyRow above it
                emptyRow = i - 1;
            } else if (ans[i][j] == '#') {
                // Stone found; move it to the lowest available position
                swap(ans[i][j], ans[emptyRow][j]);
                emptyRow--; // Update the lowest available position
            }
        }
    }
    return ans;
}

};