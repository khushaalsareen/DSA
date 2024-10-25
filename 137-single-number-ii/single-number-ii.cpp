class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        for(int bit = 0; bit<32; bit++){
            int cnt = 0;
            for(auto it:nums){
                if((1<<bit) & it)
                cnt++;
            }
            if(cnt%3 ==1){
                //set this ith bit
                num = num | (1<<bit);
            }
        }
        return num;
    }
};