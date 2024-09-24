class Solution {
public:
    pair<int,pair<int,int>> f(string &s, int i, int j){
        int len = 1;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            len+=2;
            i--;
            j++;
        }
        return {len,{i+1,j-1}};
    }
    pair<int,pair<int,int>> e(string &s, int i, int j){
        int len = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            len+=2;
            i--;
            j++;
        }
        return {len,{i+1,j-1}};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int sp;
        int ep;
        for(int i=0;i<n;i++){
            // expand around centre i
            pair<int,pair<int,int>> oddlen = f(s,i-1,i+1);
            pair<int,pair<int,int>> evenlen = e(s,i-1,i);
            if(oddlen.first>evenlen.first)
            {
                if(oddlen.first>ans.size()){
                    ans = s.substr(oddlen.second.first,oddlen.first);
                }
            }
            else{
                if(evenlen.first>ans.size()){
                    ans = s.substr(evenlen.second.first,evenlen.first);
                }
            }
        }
        return ans;
    }
};