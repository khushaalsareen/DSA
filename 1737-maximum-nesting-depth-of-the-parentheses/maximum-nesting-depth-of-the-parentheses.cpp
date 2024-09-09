class Solution {
public:
    int maxDepth(string s) {
        int opened = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                opened++;
                ans = max(ans,opened);
            }
            else if(s[i]==')'){
                opened--;
            }
            
        }
        return ans;
    }
};