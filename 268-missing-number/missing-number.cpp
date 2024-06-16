class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xo = 0;
        for(auto it: nums)
        xo^=it;
        for(int i=0;i<=nums.size();i++){
            xo^=i;
        }
        return xo;
    }
};