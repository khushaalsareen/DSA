class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int currMin = nums[n-1];
        int start = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>currMin)
            start = i;
            else
            currMin = nums[i];
        }
        int end=  0;
        int currMax = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>=currMax)
            currMax = nums[i];
            else
            end = i;
        }
        if(start == n-1)
        return 0;
        return end - start + 1;
    }
};