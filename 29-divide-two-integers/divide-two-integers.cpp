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
        long ans = 0;
        while(dd>=dv){
            long cnt = 0;
            while((dv*(1L<<(cnt+1)))<=dd){
                cnt++;
            }
            dd = dd - (dv*(1L<<(cnt)));
            ans = ans + (1L<<(cnt));
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