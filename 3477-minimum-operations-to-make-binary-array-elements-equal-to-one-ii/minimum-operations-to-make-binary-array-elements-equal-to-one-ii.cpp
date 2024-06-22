class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1])
            cnt++;
        }
        if(nums[0]==0)
        return 1 + cnt;
        return cnt;
        
    }
};