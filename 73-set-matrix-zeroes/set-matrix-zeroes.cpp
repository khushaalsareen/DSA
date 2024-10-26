class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n  = matrix[0].size();
        bool isRow = false, isCol = false;
        for(int i=0;i<n;i++){
            if(matrix[0][i] == 0)
            isRow = true;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
            isCol = true;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // travsersing over rows
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //traversing over cols
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int r=1;r<m;r++){
                    matrix[r][i] = 0;
                }
            }
        }
        if(isRow){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
        if(isCol){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};