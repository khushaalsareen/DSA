class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());

        // dp[k] = set of all sums possible using k elements
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);

        for (int num : nums) {
            for (int k = n - 1; k >= 0; --k) {
                for (int s : dp[k]) {
                    dp[k + 1].insert(s + num);
                }
            }
        }

        for (int k = 1; k < n; ++k) {
            if ((totalSum * k) % n != 0) continue;
            int target = (totalSum * k) / n;
            if (dp[k].count(target)) return true;
        }

        return false;
    }
};
