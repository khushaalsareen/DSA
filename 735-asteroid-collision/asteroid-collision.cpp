class Solution {
public:
    vector<int> asteroidCollision(vector<int>&nums) {
        vector<int>ans;
        int n = nums.size();
        stack<int>s;
        for(int i=0;i<n;){
           
                bool var = true;
                while(!s.empty() && s.top()>0 && nums[i]<0){
                    int val = s.top();
                    if(abs(nums[i])>abs(val)){
                        s.pop();
                    }
                    else if(abs(nums[i])==abs(val)){
                        s.pop();
                        i++;
                        var = false;
                        break;
                    }
                    else{
                        i++;
                        var = false;
                        break;
                    }
                }
                  if(i<nums.size() && var !=false)
                    s.push(nums[i++]);
            }
         
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};