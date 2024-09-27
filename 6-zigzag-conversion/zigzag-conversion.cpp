class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string>v(numRows+1,"");
        int i = 1;
        int j = 0;
        if(numRows == 1)
        return s;
        bool fg = true;
        while(j<n){
            if(i>numRows){
                i = numRows-1;
                fg = false;
            }
            if(i==0){
                i = 1 + 1;
                fg = true;
            }
            
            v[i].push_back(s[j]);
            fg == false ? i-- : i++;
            j++;
        }
        string ans = "";
        for(int k = 1;k<v.size();k++){
            ans = ans + v[k];
        }
        return ans;
    }
};