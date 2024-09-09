class Solution {
public:
    int minInsertions(string str) {
        int cnt = 0;
        int opened = 0;
        for(int i=0;i<str.size();){
            if(str[i]=='('){
                // s.push('(');
                opened++;
                i++;
            }
            else{
                if(opened == 0){
                    cnt++;
                }
                if(opened>0){
                    opened--;
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
        cnt+=2*opened;
        return cnt;
    }
};