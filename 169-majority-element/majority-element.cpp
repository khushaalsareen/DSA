class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = -1e9-1;
        int freq= 0;
        int i =0;
        while(i<nums.size()){
            if(nums[i]==maj)
            freq++;
            else if(freq==0){
                maj = nums[i];
                freq = 1;
            }
            else
            freq--;
            i++;
        }
        return maj;
    }
};