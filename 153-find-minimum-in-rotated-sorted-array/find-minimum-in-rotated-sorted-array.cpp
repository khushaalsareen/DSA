class Solution {
public:
    int pivot(vector<int>&nums){
        int l= 0;
        int h = nums.size()-1;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(nums[m]<=nums[nums.size()-1])
            h = m - 1;
            else
            {
               if(nums[m]>nums[m+1])
               return m;
               else
               l = m+1; 
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int piv = pivot(nums);
        if(piv==-1)
        return nums[0];
        return nums[piv+1];
    }
};