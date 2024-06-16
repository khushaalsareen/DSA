class Solution {
public:
    bool check(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(i+1<n and nums[i]>nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1)
        return true;

        for(int i = idx +1;i<n;i++){
            if(i+1<n && nums[i]>nums[i+1])
            return false;
        }

        if(nums[n-1]<=nums[0])
        return true;
        return false;
    }
};