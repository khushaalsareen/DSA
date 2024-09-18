class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mid;
        if(n==1)
        return nums[0];

        while(l<=h){
            mid = l+(h-l)/2;
            if(mid%2 == 0){
                if(mid == 0 && nums[mid]!=nums[mid+1])
                return nums[0];
                else if(mid == n-1 && nums[mid]!=nums[ mid-1])
                return nums[mid];
                else if(mid+1<nums.size() && mid-1>=0 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
                else if(nums[mid]==nums[mid+1])
                l = mid+1;
                else
                h = mid - 1;
            }
            else{
                if(mid-1>=0 && nums[mid]==nums[mid-1])
                l = mid + 1;
                else
                h = mid -1 ;
            }
        }
        return -1;
    }
};