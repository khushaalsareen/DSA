class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0;
        int h = mat[0].size()-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            
            int maxEle = -1;
            int maxIdx = -1;
            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>maxEle){
                    maxEle = mat[i][mid];
                    maxIdx = i;
                }
            }
        
            int left = mid-1>=0? mat[maxIdx][mid-1]: -1;
            int right = mid+1<mat[0].size() ? mat[maxIdx][mid+1]: 1;
            if(maxEle > left and maxEle>right)
            return {maxIdx, mid};
            else if(maxEle<left)
            h = mid - 1;
            else
            l = mid + 1;
        }
        return {0,0};
    }
};