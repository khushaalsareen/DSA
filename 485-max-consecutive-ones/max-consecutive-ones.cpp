class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int prev = 0;
        if(nums[0]==1)
        prev = 1;
        ans = max(ans,prev);
        for(int i = 1; i<nums.size();i++){
            int curr = 0;
            if(nums[i]==1)
             curr = 1 + prev;
            else
            curr = 0;
            ans = max(ans,curr);
            prev = curr;
        }
        return ans;
    }

};