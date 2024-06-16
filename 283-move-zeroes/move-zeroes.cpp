class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // place correct element at this postion
        int j = 0;
        while(j<nums.size()){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
};