class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero = 0, countOne = 0, countTwo = 0;
        for(auto it: nums){
            if(it == 0)
            countZero++;
            else if(it == 1)
            countOne++;
            else
            countTwo++;
        }
        int i = 0;
        while(countZero--){
            nums[i] = 0;
            i++;
        }
        while(countOne--){
            nums[i] = 1;
            i++;
        }
        while(countTwo--){
            nums[i] = 2;
            i++;
        }
    }
};