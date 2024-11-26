class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        int top = 0;
        int bottom = n-1;
        int midrow;
        while(top<=bottom){
            midrow = top + (bottom-top)/2;
            int maxCol = 0;
            for(int c = 0;c<m;c++){
                if(mat[midrow][c]>mat[midrow][maxCol]){
                    maxCol = c;
                }
            }
                bool isPeak = true;
                if(midrow>0 && mat[midrow][maxCol]<mat[midrow-1][maxCol]){
                    isPeak = false;
                    bottom = midrow-1;
                }
                if(midrow<n-1 && mat[midrow][maxCol]<mat[midrow+1][maxCol]){
                    isPeak = false;
                    top = midrow + 1;
                }
                if(isPeak)
                return {midrow,maxCol};
            }
        
        return {1,1};
    }   
     
};