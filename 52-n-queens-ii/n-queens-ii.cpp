class Solution {

    bool is_valid(int r, int c, unordered_set<int>&cols,unordered_set<int>&ld,unordered_set<int>&rd){
        
            if(cols.find(c)!=cols.end() || ld.find(r-c)!=ld.end() || rd.find(r+c)!=rd.end() )
            return false;
        
        return true;
    }
    void generate(int r,unordered_set<int>&cols,unordered_set<int>&ld,unordered_set<int>&rd, int &cnt, int n){
        if(r == n){
            // ans.push_back(v);
            cnt++;
            return;
        }
        // do all stuff on current level
        // i can try to plcae queen from 0 to n-1
        for(int c = 0;c<n;c++){
            if(is_valid(r,c,cols,ld,rd)){
                // v[r][c] = 'Q';
                cols.insert(c);
                ld.insert(r-c);
                rd.insert(r+c);
                generate(r+1,cols,ld,rd,cnt,n);
                // v[r][c] = '.'; // backyracking
                cols.erase(c);
                ld.erase(r-c);
                rd.erase(r+c);
            }
        }
    }
    int solveNQueens(int n) {
        // vector<vector<string>> ans;
        // vector<string>v(n,string(n,'.'));
        unordered_set<int>cols;
        unordered_set<int>ld;
        unordered_set<int>rd;
        int cnt = 0;
        generate(0,cols,ld,rd,cnt,n);
        return cnt;
    }

public:
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};