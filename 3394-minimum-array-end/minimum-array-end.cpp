class Solution {
public:
    long long minEnd(int n, int x) {
        long long int num = x;
        long long int size = 1;
        // long long int lastNum = num;
        while(size !=n){
            
            num = x | (num+1);
            // lastNum = num;
            size++;
        }
        return num;
    }

};