class Solution {
public:
    void generate(int open, int close, int n, string &s, vector<string>&ans){
        if(open == 0){
            int tmp = close;
            while(close!=0){
                s.push_back(')');
                close--;
            }
            ans.push_back(s);
            while(close!=tmp){
                s.pop_back();
                close++;
            }
            return;
        }

        if(open == close)
        {
            s.push_back('(');
            generate(open-1,close,n,s,ans);
            s.pop_back();
        }
        else if(open < close){
            s.push_back('(');
            generate(open-1,close,n,s,ans);
            s.pop_back();
            s.push_back(')');
            generate(open,close-1,n,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        /*

        n (
        n )

        cnt ( >= cnt )
        (
        cnt of closing braces 
        prefix  = n - value
        prefix = ()

        ( == )
        start with (

        ( < )
        two choices

        ( > )
        not possibel
        )        
        */
        string s = "";
        vector<string>ans;
        generate(n,n,n,s,ans);
        return ans;
    }
};