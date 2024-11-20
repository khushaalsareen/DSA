class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k;i++){
            if(dq.empty() || nums[i]<=nums[dq.back()])
            dq.push_back(i);
            else{
                while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            if(dq.front()==i-k)
            dq.pop_front();
            if(dq.empty() || nums[i]<=nums[dq.back()])
            dq.push_back(i);
            else{
                while(!dq.empty() && nums[dq.back()]<=nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;           
    }
};