class Solution {
public:
    bool f(int mid, vector<int>&nums, long long k){
        long long int cnt = 0;
        for(auto it:nums){
            cnt = cnt + it/mid;
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        long long int sum = 0;
        int n = nums.size();
        for(auto it:nums){
            sum+=it;
        }
        if(sum<k)
        return 0;

        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            bool check = f(mid, nums, k);
            if(check){
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};