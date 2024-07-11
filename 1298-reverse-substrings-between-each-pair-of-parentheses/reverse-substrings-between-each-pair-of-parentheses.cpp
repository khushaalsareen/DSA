class Solution {
public:
    void reverse(string &ans, int i, int j){
        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    }
    string reverseParentheses(string s) {
        vector<int>v;
        string ans = "";
       
       int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
           { 
            
            cnt++;
            // cout<<i<<" "<<s[i]<<cnt<<endl;
           }
            if(s[i]=='('){
                v.push_back(i);
            }
            else if(s[i]==')'){
                int prevIdx = v.back() + 1;
                v.pop_back();
                int currIdx = i-1;
                // cout<<cnt<<" ";
              
                reverse(s,prevIdx,currIdx);
            }
            if(s[i]==')')
            cnt++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')')
            continue;
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};