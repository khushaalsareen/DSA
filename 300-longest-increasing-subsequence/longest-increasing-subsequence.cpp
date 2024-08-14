class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(res.back()<nums[i])
            res.push_back(nums[i]);
            else{
                int idx = lower_bound(res.begin(),res.end(),nums[i]) - res.begin();
                res[idx] = nums[i];
            }
        }
        return res.size();   
    }
};