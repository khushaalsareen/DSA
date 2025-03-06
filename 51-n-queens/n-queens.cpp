class Solution {
public:
    bool is_valid(int r, int c, vector<string>&v, vector<int>&cols){
        
        for(int i=0;i<r;i++){
            if(cols[i]==c || abs(r-i)==abs(c-cols[i]))
            return false;
        }
        return true;
    }
    void generate(int r, vector<string>&v, vector<vector<string>>&ans,vector<int>&cols){
        if(r == v.size()){
            ans.push_back(v);
            return;
        }
        // do all stuff on current level
        // i can try to plcae queen from 0 to n-1
        for(int c = 0;c<v.size();c++){
            if(is_valid(r,c,v,cols)){
                v[r][c] = 'Q';
                cols[r] = c;
                generate(r+1,v,ans,cols);
                v[r][c] = '.'; // backyracking
                cols[r] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n,string(n,'.'));
        vector<int>cols(n,-1);
        generate(0,v,ans,cols);
        return ans;
    }
};