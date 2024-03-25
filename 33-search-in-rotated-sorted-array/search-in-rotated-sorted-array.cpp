class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(nums[m]==target) return m;
            else if(nums[l]<=nums[m]){ // left half is sorted
                if(nums[l]<=target && target<=nums[m])
                h = m-1;
                else
                l = m+1;
            }
            else{
                if(nums[m]<=target && target<=nums[h])
                l = m+1;
                else
                h = m-1;
            }
        }
        return -1;
    }
};