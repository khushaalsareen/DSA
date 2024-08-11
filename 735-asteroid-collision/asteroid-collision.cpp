class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>ans;
        stack<int>s;
        s.push(0);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>0)
            s.push(i);
            //collsiion will occur
            bool survived = true;
            while(!s.empty() && arr[i]*arr[s.top()]<0){
                int x = s.top(); // index of last element on top of stack
                s.pop();
                if(abs(arr[x])>abs(arr[i])){
                    s.push(x);
                    survived = false;
                    break;
                }
                else if(abs(arr[x])==abs(arr[i]))
                {
                    survived = false;
                    break;
                }
                else
                continue; // continue knocking out elements from stack
            }
            if(survived && (s.empty() || arr[s.top()]<0))
            s.push(i);   
        }
        while(!s.empty()){
            ans.push_back(arr[s.top()]);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};