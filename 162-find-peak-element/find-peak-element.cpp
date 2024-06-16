class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int h = nums.size()-1;
        if(n==1) return 0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(mid == n-1 and nums[mid]>nums[mid-1])
            return mid;
            else if(mid==0 and nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1])
            return mid;
            else if(nums[mid]<nums[mid+1])
            l = mid +1;
            else
            h = mid-1;
        }
        return -1;
    }
};