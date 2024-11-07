class Solution {
public:
    int nthUglyNumber(int n) {
        map<long long int,int>m;
        m[1]++;
        auto it = m.begin();
        int cnt = 0;
        while(true){
            auto it = m.begin();
            long long int ele = it->first;
            m.erase(ele);
            cnt++;
            if(cnt == n)
            return ele;
            m[ele*1LL*2]++;
            m[ele*1LL*3]++;
            m[ele*1LL*5]++;
        }
        return -1;
    }
};