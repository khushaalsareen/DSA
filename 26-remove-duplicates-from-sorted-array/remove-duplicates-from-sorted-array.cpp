class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int j = 1;
        while(j<n){
            if(nums[i-1]!=nums[j]){
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        return i;
    }
};