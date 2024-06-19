class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int top = 0;
        int bottom = rows - 1;
        
        while (top <= bottom) {
            int midRow = top + (bottom - top) / 2;
            int maxCol = 0;
            
            for (int c = 0; c < cols; ++c) {
                if (mat[midRow][c] > mat[midRow][maxCol]) {
                    maxCol = c;
                }
            }
            
            bool isPeak = true;
            if (midRow > 0 && mat[midRow][maxCol] < mat[midRow - 1][maxCol]) {
                isPeak = false;
                bottom = midRow - 1;
            } 
            if (midRow < rows - 1 && mat[midRow][maxCol] < mat[midRow + 1][maxCol]) {
                isPeak = false;
                top = midRow + 1;
            }
            
            if (isPeak) {
                return {midRow, maxCol};
            }
        }
        
        return {-1, -1};
    }
};
