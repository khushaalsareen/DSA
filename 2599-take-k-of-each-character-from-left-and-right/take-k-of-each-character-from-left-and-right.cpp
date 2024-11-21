class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        if(k == 0)
        return 0;
        int cntA =  0;
        int cntB = 0;
        int cntC = 0;
        for(auto it:s){
            if(it == 'a')
            cntA++;
            else if(it == 'b')
            cntB++;
            else
            cntC++;
        }
        if(cntA<k || cntB<k || cntC<k)
        return -1;

        int ans = n;
        int chars = k*3;
        
      
        
        //left = 0
        int i = 0;
        int j = n-1;
        int cnta = 0, cntb = 0, cntc = 0;
        while(j>=0 && ((cnta<k)||(cntb<k)||(cntc<k))){
            if(s[j]=='a')
            cnta++;
            else if(s[j]=='b')
            cntb++;
            else
            cntc++;
            j--;
        }
        j++;
        ans = min(ans,n-j);
        cout<<ans;
        // left se uthao from 1 to n
        i = 0;
        
        while(i<n){
            if(s[i]=='a')
            cnta++;
            else if(s[i]=='b')cntb++;
            else
            cntc++;
                while(j<n && ((cnta>=k)&&(cntb>=k) &&(cntc>=k))){
                    if(s[j]=='a')
                    cnta--;
                    else if(s[j]=='b')
                    cntb--;
                    else
                    cntc--;
                    j++;
                }
            int res;
            if(j==n && cnta>=k && cntb>=k &&cntc>=k)
            res = i+1 + n - j;
            else
             res = i+1 + n - j+1;
            if(s[j-1]=='a')cnta++;
            else if(s[j-1]=='b')cntb++;
            else
            cntc++;
            j--;
            ans = min(ans,res);
            i++;    
        }
        return ans;
    }
};