class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sum = (n*(n+1))/2;
        for(auto it: nums)
        sum= sum - it;
        return (int)sum;
    }
};