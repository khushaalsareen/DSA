class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // last unique element over here
        int j = 1;  // pointer iterating over array
        while(j<nums.size()){
            if( nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
                
            }
            j++;
        }
        return i+1;
    }
};