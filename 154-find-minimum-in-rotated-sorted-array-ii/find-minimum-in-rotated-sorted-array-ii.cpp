class Solution {
public:
    int findMin(vector<int>& nums) {
         int ans = INT_MAX;
        int l = 0;
        int n = nums.size();
        int h = n-1;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(nums[l]==nums[m] && nums[m]==nums[h]){
                ans = min(ans,nums[m]);
                l++;
                h--;
            }
            else if(nums[l]<=nums[m]){ // left part is sorted
                ans = min(ans,nums[l]);
                l = m+1;
            }
            else{
                ans = min(ans,nums[m]);
                h = m-1;
            }
        }
        return ans;
    }
};