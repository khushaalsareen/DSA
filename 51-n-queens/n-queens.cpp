class Solution {
public:
    bool is_valid(int r, int c, vector<string>&v, unordered_set<int>&cols,unordered_set<int>&ld,unordered_set<int>&rd){
        
        for(int i=0;i<r;i++){
            if(cols.find(c)!=cols.end() || ld.find(r-c)!=ld.end() || rd.find(r+c)!=rd.end() )
            return false;
        }
        return true;
    }
    void generate(int r, vector<string>&v, vector<vector<string>>&ans,unordered_set<int>&cols,unordered_set<int>&ld,unordered_set<int>&rd){
        if(r == v.size()){
            ans.push_back(v);
            return;
        }
        // do all stuff on current level
        // i can try to plcae queen from 0 to n-1
        for(int c = 0;c<v.size();c++){
            if(is_valid(r,c,v,cols,ld,rd)){
                v[r][c] = 'Q';
                cols.insert(c);
                ld.insert(r-c);
                rd.insert(r+c);
                generate(r+1,v,ans,cols,ld,rd);
                v[r][c] = '.'; // backyracking
                cols.erase(c);
                ld.erase(r-c);
                rd.erase(r+c);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n,string(n,'.'));
        unordered_set<int>cols;
        unordered_set<int>ld;
        unordered_set<int>rd;
        generate(0,v,ans,cols,ld,rd);
        return ans;
    }
};