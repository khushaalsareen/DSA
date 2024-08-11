class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        vector<int>PSE(n,-1);
        vector<int>NSE(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            // when am I removing from stack obly if nums[i]<nums[s.top()]
            while(!s.empty() and nums[i]<nums[s.top()]){
                PSE[s.top()] = i;
                s.pop();
            }
            // else I am pushing in stack always since I wannna find PSE or NSE OF each element
            if(s.empty() || nums[i]>=nums[s.top()])
            s.push(i);
        }
        while(!s.empty())
        s.pop();
        s.push(0);
        for(int i = 1;i<n;i++){
            while(!s.empty() and nums[i]<nums[s.top()]){
                NSE[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int psI = PSE[i];
            int nsI = NSE[i];
            maxArea = max(maxArea, (nsI-psI-1)*nums[i]);
        }
        return maxArea;
    }
};