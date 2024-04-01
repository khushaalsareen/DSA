class Solution {
public:
    int findGCD(int a, int b){
        a = abs(a);
        b = abs(b);
        if(a==0) return b;
        return findGCD(b%a,a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int gcd = 0;
        unordered_map<int,int>m;
        for(auto it: deck){
            m[it]++;
        }
        for(auto it = m.begin();it!=m.end();it++){
            gcd = findGCD(gcd,it->second);
        }
        return gcd>1;
    }
};