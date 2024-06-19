class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = m*n  - 1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            int r = mid/n;
            int c = mid%n;
            if(matrix[r][c]==target)
            return true;
            else if(matrix[r][c]>target)
            h = mid - 1;
            else
            l = mid + 1;
        }
        return false;
    }
};