class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n  = nums.size();
        int minPrev = 1e9;
        int maxPrev = -1e9;
        int minCurr = 1e9;
        int maxCurr = -1e9;
        int i = 0;
        while(i<n){
            int currMin = nums[i];
            int currMax = nums[i];
            int cnt = __builtin_popcount(nums[i]);
            int j = i;
            while(j<n && __builtin_popcount(nums[j]) == cnt){
                currMin = min(currMin,nums[j]);
                currMax = max(currMax,nums[j]);
                j++;
            }
            // i - > j - 1
            if(currMin<maxPrev)
            return false;

            minPrev = currMin;
            maxPrev = currMax;
            i = j;
        }
        return true;
    }
};