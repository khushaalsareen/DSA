class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
            int n  = nums.size();
            stack<int>s;
            s.push(nums[0]);
            for(int i=1;i<n;){
                if(!s.empty() && (s.top()>0 && nums[i]<0)){
                    if(abs(s.top())>abs(nums[i])){
                        i++;
                    }
                    else if(abs(s.top())==abs(nums[i])){
                        s.pop();
                        i++;
                    }
                    else{
                        s.pop();
                    }
                }
                else{
                    s.push(nums[i]);
                    i++;
                }
            }
            vector<int>ans;
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};