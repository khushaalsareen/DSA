class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_map<string,int>m;
        for(int i=0;i<matrix.size();i++){
            int ele = matrix[i][0];
            string s = "";
            for(int j = 0;j<matrix[0].size();j++){
                if(ele == matrix[i][j])
                s.push_back('1');
                else
                s.push_back('0');
            }
            m[s]++;
        }
        int maxi = 1;
        for(auto it:m){
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};