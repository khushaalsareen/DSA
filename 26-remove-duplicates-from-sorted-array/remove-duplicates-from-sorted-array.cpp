class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = -1; // last unique element over here
        int j = 0;  // pointer iterating over array
        while(j<nums.size()){
            if(i==-1 || nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
                
            }
            j++;
        }
        return i+1;
    }
};