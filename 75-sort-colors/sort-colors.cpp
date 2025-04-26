class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // before this all 0
        int j = 0; // to traverse over array
        int k = n-1; // after this all 2
        for(;j<=k;){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==1){
                j++;
            }
            else{
                swap(nums[k],nums[j]);
                k--;
            }
        }
    }
};