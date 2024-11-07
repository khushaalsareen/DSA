class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int maxAns = 1;
        for(int bitIdx=0;bitIdx<24;bitIdx++){
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if((1<<bitIdx) & nums[i])
                cnt++;
            }
            maxAns =max(maxAns,cnt);
        }
        return maxAns;
    }
};