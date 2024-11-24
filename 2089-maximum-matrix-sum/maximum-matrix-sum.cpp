class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int smallestVal = 1e9;
        int cntNeg = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int c = matrix[i][j];
                sum+=abs(c);
                smallestVal = min(smallestVal,abs(c));
                if((j+1<n && matrix[i][j+1]==0) ||  (i+1<n && matrix[i+1][j]==0))
                continue;

                if(c<0)
                {
                    cntNeg++;
                
                }
            }
        }
        cout<<sum<<endl;
        if(cntNeg%2==0)
        return sum;
        return sum - 2*1LL*smallestVal;
    }
};