class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxOnes = 0;
        int zerosCount = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zerosCount++;
            }

            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }

            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }

        return maxOnes;
    }
};
