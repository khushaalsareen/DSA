class Solution {
public:
    int first(vector<int>&nums, int target){
        int l = 0;
        int h = nums.size()-1;
        int mid;
        int ans = -1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]<target)
            l = mid+1;
            else if(nums[mid]>target)
            h = mid - 1;
            else{
                ans = mid;
                h =mid-1;
            }
        }
        return ans;
    }

    int last(vector<int>&nums, int target){
        int l = 0;
        int h = nums.size() - 1;
        int mid;
        int ans = -1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]>target){
                h = mid-1;
            }
            else if(nums[mid]<target)
            l = mid+1;
            else{
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int st = first(nums,target);
        int ep = last(nums,target);
        if(st == -1)
        return {-1,-1};
        ans.push_back(st);
        ans.push_back(ep);
        return ans;
    }
};