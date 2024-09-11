class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(mid%2 == 0){
                if(mid+1<nums.size() and nums[mid]==nums[mid+1])
                l = mid+1;
                else if(mid-1>=0 and nums[mid]==nums[mid-1])
                h = mid-1;
                else
                return nums[mid];
            }
            else{
                if(mid-1>=0 and nums[mid]==nums[mid-1])
                l = mid+1;
                else 
                h = mid -1;
                
            }
        }
        return -1;
    }
};