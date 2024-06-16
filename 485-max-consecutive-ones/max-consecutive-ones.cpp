class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = -1;
        int j = 0;
        int ans = 0;
        while(j<nums.size()){
            if(nums[j]==1){
                i = j;
                while(j<nums.size() && nums[j]==1)
                j++;
                ans = max(ans,j-i);
            }
            else
            j++;
        }
        return ans;
    }
};