class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = -1;
        int freq= 0;
        int i =0;
        while(i<nums.size()){
            if(freq==0){
                maj = nums[i];
                freq = 1;
            }
            else if(maj == nums[i])
            freq++;
            else
            freq--;
            i++;
        }
        return maj;
    }
};