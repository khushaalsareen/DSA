class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!s.empty() && k>0 && (s.top()-'0')>(num[i]-'0')){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        string ans = "";
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<ans.size() && ans[i]=='0'){
            
            i++;
           
        }
        ans = ans.substr(i);
        return ans.empty()?"0":ans;
    }
};