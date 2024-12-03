class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        if(spaces[0]==0)
        ans = ans + " ";
        int idx = 0;
        if(spaces[0]==0)
        idx++;
        int i = 0;
        for(;idx<spaces.size();idx++){
            int j = spaces[idx]- 1;
            ans += s.substr(i,j-i+1) ;
            ans+=" ";
            i = spaces[idx];
        }
        ans += s.substr(i,s.size()-i);
        return ans;
    }
};