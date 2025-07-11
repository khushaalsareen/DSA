class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(n==1)
        return nums[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(mid == 0){
                if(nums[mid]==nums[mid+1])
                l = mid + 1;
                else
                return nums[mid];
            }
            else if(mid == n-1){
                if(nums[mid]==nums[mid-1])
                h = mid-1;
                else
                return nums[mid];
            }
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            else if(mid%2 == 0){
                if(nums[mid]==nums[mid+1])
                l = mid+1;
                else
                h = mid-1;
            }
            else{
                if(nums[mid]==nums[mid-1])
                l = mid + 1;
                else
                h = mid - 1;
            }
        }
        return nums[0];
    }
};