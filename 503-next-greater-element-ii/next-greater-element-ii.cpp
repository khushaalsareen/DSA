class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        st.push(0);
        vector<int>ans(nums.size(),-1);
        for(int i=1;i<nums.size();i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nums.size();i++){
            if(st.empty())break;
            while(!st.empty() && nums[i]>nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop();
            }
        }
        return ans;
    }
};