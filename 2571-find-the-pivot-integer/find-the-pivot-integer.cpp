class Solution {
public:
    int pivotInteger(int n) {
        for(int x=1;x<=n;x++){
            int leftSum = (x*(x+1))/2;
            int rightSum = (n*(n+1))/2 - ((x-1)*x)/2;
            if(leftSum==rightSum)
            return x;
        }
        return -1;
    }
};