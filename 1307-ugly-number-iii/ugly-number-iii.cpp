class Solution {
     long long int LCM(long long int a,long long int b){
        long long int p =a*1LL*b;
        int dividend = max(a,b);
        int divisor = min(a,b);
        int remainder = dividend%divisor;
        while(remainder!=0){
            dividend = divisor;
            divisor = remainder;
            remainder = dividend%divisor;
        }
        return p/divisor;
    }
    
    long long int check(long long int n, int a, int b, int c, int p){
        long long int cntA = n/a;
        long long int cntB = n/b;
        long long int cntC = n/c;
            long long int lcm1 = LCM(a,b);
            long long int lcm2 = LCM(b,c);
            long long int lcm3 = LCM(a,c);
            long long int lcm4 = LCM(lcm1,c);
        long long int cntAB = n/lcm1;
        long long int cntBC = n/lcm2;
        long long int cntAC = n/lcm3;
        long long int cntABC = n/lcm4;
        long long int cnt = cntA + cntB + cntC - cntAB - cntBC - cntAC + cntABC;
        return cnt;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
       long long int l = min({a,b,c});

       long long int h = 2*1LL*1e9;
       long long int mid;
       long long int ans;
       while(l<=h){
        mid = l+(h-l)/2;
        // can mid be nth ugly number
        int cnt = check(mid,a,b,c,n);
       
       if(cnt<n)
        l = mid + 1;
         else 
        {
            ans = mid;
            h = mid-1;
        }
        
       }
       return ans;
    }
};