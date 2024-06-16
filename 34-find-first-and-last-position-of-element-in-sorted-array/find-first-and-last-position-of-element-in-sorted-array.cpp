class Solution {
public:
    int first(vector<int>&nums, int target){
        int l = 0;
        int h = nums.size()-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]>target)
            h = mid-1;
            else if(nums[mid]<target)
            l = mid+1;
            else{
                if(mid-1>=0 && nums[mid-1]==nums[mid])
                h = mid-1;
                else
                return mid;
            }
        }
        return -1;
    }
    int last(vector<int>&nums, int target){
        int l = 0;
        int h = nums.size()-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]>target)
            h = mid-1;
            else if(nums[mid]<target)
            l = mid+1;
            else{
                if(mid+1<nums.size() && nums[mid+1]==nums[mid])
                l = mid+1;
                else
                return mid;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int s = last(nums,target);
        
        vector<int>ans;
        ans.push_back(f);
        ans.push_back(s);
        return ans;
    }
};