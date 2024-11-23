class Solution {
public:
    bool f(int mid, vector<int>&nums, int days){
        int cnt = 1;
        int wt = nums[0];
        for(int i=1;i<nums.size();i++){
            if(wt + nums[i]<=mid){
                wt+=nums[i];
            }
            else{
                cnt++;
                wt = nums[i];
            }
        }
        return cnt<=days;
    }

    int shipWithinDays(vector<int>& nums, int days) {
        int l = *max_element(nums.begin(),nums.end());
        int h = 0;
        for(auto it:nums)
        h+=it;
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            bool check = f(mid,nums,days);
            if(check){
                ans =mid;
                h = mid-1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};