class Solution {
public:
    bool isUgly(int n) {
        long long int x = abs(n);
        if(n<0) return false;
        if(n==0) return false;
        while(x>1){
            cout<<x<<endl;
            if(x%2 == 0)
            x/=2;
            else if(x%3 ==0)
            x/=3;
            else if(x%5 == 0)
            x/=5;
            else 
            return false;
        }
        return true;
    }
};