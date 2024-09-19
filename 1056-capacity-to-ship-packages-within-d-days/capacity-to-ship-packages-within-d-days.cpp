class Solution {
public:
    bool f(int mid, vector<int>&nums, int days){
        int cnt = 1;
        int load = 0;
        for(int i=0;i<nums.size();i++){
        if(load + nums[i]<=mid){
                load+=nums[i];
            }
            else{
                cnt++;
                load = nums[i];
            }
        }

        if(cnt>days)
        return false;
        return true;
    }
    int shipWithinDays(vector<int>&nums, int days) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int h;
        int sum = 0;
        for(auto it:nums){
            sum+=it;
        }
        h = sum;
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(f(mid,nums,days)){
                ans = mid;
                h = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
};