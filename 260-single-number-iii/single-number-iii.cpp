class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long int xorNum = 0;
        for(auto it:nums){
            xorNum^=it;
        }
        long int rightMostBitVal = (xorNum^(xorNum-1L))&xorNum;
        int b1 = 0;
        int b2 = 0;
        for(auto it:nums){
            if(it & rightMostBitVal)
            b1^=it;
            else
            b2^=it;
        }
        return {b1,b2};

    }
};