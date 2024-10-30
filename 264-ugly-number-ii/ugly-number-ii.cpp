class Solution {
public:
    void find(map<long long int,int>&m, int n, int &ans,auto &itr, int &cnt){
       
        cnt++;
        if(cnt==n){
            ans = itr->first;
            return;
        }
        long long int val1 = itr->first*1LL*2;
        long long int val2 = itr->first*1LL*3;
        long long int val3 = itr->first*1LL*5;
        m[val1]++;
        m[val2]++;
        m[val3]++;
        itr++;
        find(m,n,ans,itr,cnt);
    }
    int nthUglyNumber(int n) {
        map<long long int, int>m;
        m[1*1LL]++;
        int ans = 1;
        auto itr = m.begin();
        int cnt=0;
        find(m,n,ans,itr,cnt);
        return ans;
    }
};