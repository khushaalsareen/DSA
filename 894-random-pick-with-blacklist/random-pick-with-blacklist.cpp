class Solution {
unordered_map<int,int>m;
int valid;
public:
    Solution(int n, vector<int>& blacklist) {
        //valid = 0;
        for(int i=0;i<blacklist.size();i++){
            m[blacklist[i]] = -1;
        }
         valid = n - blacklist.size();
        for(int i=0;i<blacklist.size();i++){
            int curr = blacklist[i];
            if(curr>=valid) continue;
            while(m.find(n-1)!=m.end()){
                n--;
            }
            m[curr] = n-1;
            n--;
        }
    }
    
    int pick() {
        int val = rand()%valid;
        if(m.find(val)==m.end())
        return val;
        return m[val];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */