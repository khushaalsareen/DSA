class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        if(n1!=n2)
        return false;
        for(int i=0;i<n1;i++){
            char ch = s[0];
            for(int i=0;i<n1-1;i++){
                s[i] = s[i+1];
            }
            s[n1-1] = ch;
            if(s==goal)
            return true;
        }
        return false;
    }
};