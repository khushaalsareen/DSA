class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int cntZero = 0;
        int cntNeg = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cntZero++;
            if(nums[i]<0) cntNeg++;
        }
        if(cntZero>0)
        return 0;
        else if(cntNeg>0 && cntNeg%2 == 1) return -1;
        else return 1;
    }
};