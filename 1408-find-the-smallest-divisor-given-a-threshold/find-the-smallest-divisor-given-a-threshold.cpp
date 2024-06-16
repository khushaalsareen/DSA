class Solution {
public:
    bool f(vector<int>&nums, int mid, int threshold){
        long long int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + ceil(nums[i]/(mid*1.0));
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(f(nums,mid,threshold))
            h = mid - 1;
            else
            l = mid + 1;
        }
        return l;
    }
};