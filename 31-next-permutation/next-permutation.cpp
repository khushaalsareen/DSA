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
          int ans = -1;
          int l = i;
          int r = n-1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] > num) {
            ans = mid; // mid could be the answer
            l = mid + 1; // move right to find a smaller valid number
        } else {
            r = mid - 1;
        }
    }

        swap(nums[i-1],nums[ans]);
        int k = i;
        int j = n-1;
        while(k<j){
            swap(nums[k],nums[j]);
            k++;
            j--;
        }
    }
};