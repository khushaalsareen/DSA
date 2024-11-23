class Solution {
public:
    bool f(int mid, vector<int>&nums, int threshold){
        int sum = 0;
        for(auto it:nums){
            sum = sum + ceil(it/(mid*1.0));
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            bool check = f(mid,nums,threshold);
            if(check){
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};