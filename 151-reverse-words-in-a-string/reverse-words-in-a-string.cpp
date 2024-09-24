class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<n){
            if(s[i]==' ')
            i++;
            else
            break;
        }
        // i poiting to first char

        while(j>=0){
            if(s[j]==' ')
            j--;
            else
            break;
        }
        // j pointing to last char

        string ans = "";
        
        while(j>=i){
        int k = j;
        while(k>=i && s[k]!=' '){
            k--;
        }
        ans+=s.substr(k+1,j-k);
        if(i!=k+1)
        ans.push_back(' ');
        while(k>=i && s[k]==' '){
            k--;
        }
        j = k;
    }
    return ans;
    }

};