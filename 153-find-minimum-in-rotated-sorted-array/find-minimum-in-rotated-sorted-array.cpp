class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int m;
        int ans = 1e9;
        while(l<=h){
            m = l+(h-l)/2;
            if(nums[l]<=nums[m]){   // left sorted
                ans = min(ans,nums[l]);
                l = m + 1;
            }
            else{
                // right sorted
                ans = min(ans,nums[m]);
                h = m - 1;
            }
        }
        return ans;
    }
};