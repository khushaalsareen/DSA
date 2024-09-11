class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    long long sum = 0;
    int i = 0, j = 0;
    long long cnt1 = 0, cnt2 = 0;

    // First, count subarrays with sum exactly equal to the goal
    while (j < n) {
        sum += nums[j];
        while (sum > goal) {
            sum -= nums[i];
            i++;
        }
        cnt1 += (j - i + 1);
        j++;
    }
    if(goal == 0)
    return cnt1;
    // Reset for the next loop
    i = 0;
    j = 0;
    sum = 0;
    int newT = goal - 1;

    // Now, count subarrays with sum equal to goal - 1
    while (j < n) {
        sum += nums[j];
        while (sum > newT) {
            sum -= nums[i];
            i++;
        }
        cnt2 += (j - i + 1);
        j++;
    }

    // Return the difference
    return cnt1 - cnt2;
}
};