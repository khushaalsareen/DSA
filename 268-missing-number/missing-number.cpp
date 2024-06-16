class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xo = 0;
        
        for(int i=0;i<=nums.size();i++){
            xo^=i;
            if(i!=nums.size())
            xo^=nums[i];
        }
        return xo;
    }
};