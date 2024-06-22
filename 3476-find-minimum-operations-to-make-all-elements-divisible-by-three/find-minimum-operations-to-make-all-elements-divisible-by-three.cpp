class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i]%3;
            cnt+=min(x,3-x);
        }
        return cnt;
    }
};