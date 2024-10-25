class Solution {
public:
    int divide(int dividend, int divisor) {
        long dd = abs(dividend);
        long dv = abs(divisor);
        bool sign = true;
        if(dividend<0 && divisor >0)
        sign = false;
        if(dividend>0 && divisor<0)
        sign = false;

        if(dividend == 0)
        return 0;
        
        if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
        return INT_MIN;
        long ans = 0;
        while(dd>=dv){
            long cnt = 0;
            while((dv<<(cnt+1))<=dd){
                cnt++;
            }
            dd = dd - (dv<<cnt);
            ans = ans + (1<<cnt);
        }
        if(!sign)
        ans = -1 * ans;
        if(ans>INT_MAX)
        return INT_MAX;
        if(ans < INT_MIN)
        return INT_MIN;
        return ans;
    }
};