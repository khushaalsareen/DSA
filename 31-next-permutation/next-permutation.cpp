class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return;
        int i = n-1;
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int num = nums[i-1];
        // int idx = upper_bound(nums.begin()+i, nums.end(), num, greater<int>()) - nums.begin();
        int j = n-1;
        while (nums[j] <= num) { // find just bigger element
            j--;
        }

        swap(nums[i-1],nums[j]);
        int k = i;
        j = n-1;
        while(k<j){
            swap(nums[k],nums[j]);
            k++;
            j--;
        }
    }
};