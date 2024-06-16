class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[l]<=nums[mid]){ // left half is sorted
                if(nums[l]<=target and target<nums[mid])
                h = mid-1;
                else
                l = mid+1;
            }
            else{ // right half is sorted
                if(nums[mid]<target and target<=nums[h])
                l = mid+1;
                else
                h = mid-1;
            }
        }
        return -1;
    }
};