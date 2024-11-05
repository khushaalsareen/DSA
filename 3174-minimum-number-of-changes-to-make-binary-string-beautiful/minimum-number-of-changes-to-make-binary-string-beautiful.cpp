class Solution {
public:
    int minChanges(string s) {
       int n = s.size();
       int cnt = 0;
       vector<int>ones(n,0);
       vector<int>zero(n,0);
       if(s[0]!='0')
       ones[0] = 1;
       else
        zero[0] = 1;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                zero[i] = zero[i-1] + 1;
                ones[i] = ones[i-1];
            }
            else{
                ones[i] = ones[i-1] + 1;
                zero[i] = zero[i-1];
            }
        }
        
        int i = 0;
        while(i<n){
            int j = i+2;
            string temp  = s.substr(i,2);
            int countOnes = 0;
            int countZero = 0;
            if(temp[0]=='0')
            countZero++;
            else
            countOnes++;
            if(temp[1]=='1')
            countOnes++;
            else
            countZero++;
            if(countZero!=0 && countOnes != 0)
            cnt+=1;
            i = j;
        }
        return cnt;
    }
};