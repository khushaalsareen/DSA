class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,1);
        int curr = 0;
        int prev = 1;
        if(nums[0]==0)
        prev = 0;
        int ans = prev==0?0:1;
        for(int i = 1;i<n;i++){
            if(nums[i] == 0)
            curr = 0;
            else
            curr = max(1 + prev,1);
            ans = max(ans,curr);
            prev = curr;
        }
        return ans;
    }
};