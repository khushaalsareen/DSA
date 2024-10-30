class Solution {
private:
    bool checkOperator(char ch){
        return ch == '+' || ch == '-' || ch == '*';
    }

    int compute(int num1, int num2, char ch){
        if(ch == '+')
        return num1 + num2;
        else if(ch=='-')
        return num1-num2;
        else
        return num1*num2;
    }

    vector<int> f(string &s, int i, int j){
        vector<int>ans;
        if(i==j || j==i+1){
            int val = stoi(s.substr(i,j-i+1));
            ans.push_back(val);
            return ans;
        }
        
        for(int k=i;k<j;k++){
            char ch = s[k];
            if(checkOperator(ch)){
                vector<int>left = f(s,i,k-1);
                vector<int>right = f(s,k+1,j);
                for(auto itL: left){
                    for(auto itR:right){
                        int val = compute(itL,itR,ch);
                        ans.push_back(val);
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string s) {
            return f(s,0,s.size()-1);
    }
};