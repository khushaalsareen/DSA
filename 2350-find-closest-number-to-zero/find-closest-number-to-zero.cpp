class Solution {
public:
    
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        int ele = -1;
        int dist = 1e9;
        for(int i=0;i<n;i++){
            if(abs(nums[i])<dist){
                dist = abs(nums[i]);
                ele = nums[i];
            }
            else if(abs(nums[i])==dist && nums[i]>ele)
            ele = nums[i];

        }
        return ele;
    }
};