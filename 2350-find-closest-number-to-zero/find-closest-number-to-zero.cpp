class Solution {
public:
   
    int findClosestNumber(vector<int>& nums) {
        int minDiff = 1e9;
        int num = -1e9;
        for(int i=0;i<nums.size();i++){
            int currDiff = abs(nums[i]);
            if(currDiff<minDiff){
                minDiff = currDiff;
                num = nums[i];
            }
            else if(currDiff==minDiff){
                num=max(num,nums[i]);
            }
        }
        return num;
    }
};