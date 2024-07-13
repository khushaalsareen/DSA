class Solution {
public:
    string expand(string &s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string maxi="";
        for(int i =0;i<n;i++){
            string even = "";
            string odd = expand(s,i,i);
            if(i+1<n)
             even = expand(s,i,i+1);
            if(odd.size()>maxi.size())
            maxi = odd;
            if(even.size()>maxi.size())
            maxi = even;
        }
        return maxi;
    }
};