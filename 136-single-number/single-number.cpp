class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorC = 0;
        for(auto it:nums)
        xorC^=it;
        return xorC;
    }
};