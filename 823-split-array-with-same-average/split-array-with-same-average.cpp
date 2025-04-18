class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Memoization map: key = i|k|targetSum
        unordered_map<string, bool> memo;

        // Recursive function to check if we can pick k elements starting from i that sum to target
        function<bool(int, int, int)> dfs = [&](int i, int k, int target) {
            if (k == 0) return target == 0;
            if (i >= n || k < 0 || target < 0) return false;

            string key = to_string(i) + "|" + to_string(k) + "|" + to_string(target);
            if (memo.count(key)) return memo[key];

            // Option 1: Pick nums[i]
            if (dfs(i + 1, k - 1, target - nums[i])) return memo[key] = true;

            // Option 2: Skip nums[i]
            if (dfs(i + 1, k, target)) return memo[key] = true;

            return memo[key] = false;
        };

        // Try every group size from 1 to n-1
        for (int k = 1; k < n; ++k) {
            if ((totalSum * k) % n != 0) continue; // target sum must be an integer

            int targetSum = (totalSum * k) / n;
            if (dfs(0, k, targetSum)) return true;
        }

        return false;
    }
};
