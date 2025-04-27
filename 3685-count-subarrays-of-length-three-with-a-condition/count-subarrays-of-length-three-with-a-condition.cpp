class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            int left = i-1;
            int rt = i+1;
            if(nums[i] == 2*(nums[left] + nums[rt]))
            cnt++;
        }
        return cnt;
    }
};