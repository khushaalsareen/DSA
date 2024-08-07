class Solution {
public:
    int kadaneAlgoMax(vector<int>&nums){
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i=1;i<nums.size();i++){
            sum = max(sum+nums[i],nums[i]); // max sum ending at index i
            maxSum = max(maxSum,sum); // overall max
        }
        return maxSum;
    }
    int kadaneAlgoMin(vector<int>&nums){
        int sum = nums[0];
        int minSum =nums[0];
        for(int i=1;i<nums.size();i++){
            sum = min(nums[i],sum+nums[i]);
            minSum = min(minSum,sum);
        }
        return minSum;
    }
    int findSum(vector<int>&nums){
        int total_sum = 0;
        for(auto it:nums){
            total_sum+=it;
        }
        return total_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = kadaneAlgoMax(nums);
        int minSum = kadaneAlgoMin(nums);
        int totalSum = findSum(nums);
        if(totalSum == minSum)
        return maxSum;
        return max(maxSum, totalSum-minSum);
    }
};

