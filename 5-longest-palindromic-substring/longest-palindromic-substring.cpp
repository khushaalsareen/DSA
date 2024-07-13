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
        string maxi=s.substr(0,1);
        for(int i =0;i<n-1;i++){
            string odd = expand(s,i,i);
            string even = expand(s,i,i+1);
            if(odd.size()>maxi.size())
            maxi = odd;
            if(even.size()>maxi.size())
            maxi = even;
        }
        return maxi;
    }
};