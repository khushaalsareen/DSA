class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end())
                matrix[i][j] = 0;
            }
        }

    }
};