class Solution {
public:
    int minSubArrayLen( int k, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, i = 0, j = 0;
        int minLen = 1e9;

        while (j < n) {
            // Expand the window
            sum += nums[j];

            // Check for valid window and try to minimize it
            while (i<n && sum>=k) {
                minLen = min(minLen, j - i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return minLen == 1e9 ? 0 : minLen;
    }
};