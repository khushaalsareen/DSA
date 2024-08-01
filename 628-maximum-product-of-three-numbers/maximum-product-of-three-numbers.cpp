class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long int maxi = LLONG_MIN;
        // for(int i = 0;i<3;i++){
        int i = 0;
        long long int product = nums[i] * 1LL * nums[i + 1] * nums[i + 2];
        maxi = max(maxi, product);
        int n = nums.size();
        long long int prod2 = nums[0] * 1LL * nums[n - 1] * nums[n - 2];
        maxi = max(maxi, prod2);
        return maxi;
    }
};