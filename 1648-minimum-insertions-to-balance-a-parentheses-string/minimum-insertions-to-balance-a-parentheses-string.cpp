class Solution {
public:
    int minInsertions(string str) {
        stack<char>s;
        int cnt = 0;
        for(int i=0;i<str.size();){
            if(str[i]=='('){
                s.push('(');
                i++;
            }
            else{
                if(s.empty()){
                    cnt++;
                }
                if(!s.empty()){
                    s.pop();
                }
                if(i+1<str.size() && str[i+1]==')'){
                    i+=2;
                }
                else{
                    cnt++;
                    i++;
                }
            }
        }
        cnt+=2*s.size();
        return cnt;
    }
};