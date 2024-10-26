class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int tr = 0;
        int br = m-1;
        int lc = 0;
        int rc = n-1;
        while(tr<=br && lc<=rc){
            //traversing first row
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[tr][i]);
            }
            tr++;
            if(tr>br) break;
            //traversing rightmost column
            for(int i=tr;i<=br;i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;
            if(lc>rc) break;
            //traversing bottom row
            for(int i=rc;i>=lc;i--){
                ans.push_back(matrix[br][i]);
            }
            br--;
            if(tr>br)
            break;
            //traversing left column
            for(int i=br;i>=tr;i--){
                ans.push_back(matrix[i][lc]);
            }
            lc++;
        }
        return ans;
    }
};