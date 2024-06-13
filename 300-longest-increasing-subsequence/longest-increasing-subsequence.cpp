class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> LIS(n,1);
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                    ans = max(ans,LIS[i]);
                }
            }
        }
        return ans;
    }
};