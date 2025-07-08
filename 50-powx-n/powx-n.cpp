class Solution {
    double f(double x, long long int n){
        if(n==0)
        return 1;
        double res = f(x,n/2);
        if(n%2 == 0)
        return res * res;
        else
        return x * res * res;
    }
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(nn<0){
            nn = -nn;
            x = 1/x;
        }
        return f(x,nn);
    }
};