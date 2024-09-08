class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i]==' '){
            i++;
        }
        int j = n-1;
        while(j>=0 && s[j]==' '){
            j--;
        }
        // i---j
        int st = j;
        string ans="";
        while(j>=i){
        while(j>=i && s[j]!=' '){
            j--;
        }
        // j is at  a space
        if(ans.size()==0)
        ans = ans  + s.substr(j+1,st-j);
        else
        ans = ans + " " + s.substr(j+1,st-j);
        while(j>=i && s[j]==' '){
            j--;
        }
        st = j;
        }
        return ans;
    }
};