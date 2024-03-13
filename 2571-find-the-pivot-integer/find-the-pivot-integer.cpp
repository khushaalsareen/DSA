class Solution {
public:
    int pivotInteger(int n) {
        // for(int x=1;x<=n;x++){
        //     int leftSum = (x*(x+1))/2;
        //     int rightSum = (n*(n+1))/2 - ((x-1)*x)/2;
        //     if(leftSum==rightSum)
        //     return x;
        // }
        // return -1;

        int l = 1;
        int h = n;
        while(l<=h){
            int x = l+(h-l)/2;
            int leftSum = (x*(x+1))/2;
            int rightSum = (n*(n+1))/2 - ((x-1)*x)/2;
            if(leftSum==rightSum)
            return x;
            else if(leftSum > rightSum)
            h = x-1;
            else
            l = x+1;
        }
        return -1;
    }
};