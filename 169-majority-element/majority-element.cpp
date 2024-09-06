class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = -1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==num){
                cnt++;
            }
            else if(cnt == 0){
                num = nums[i];
                cnt = 1;
            }
            else {
                cnt--;
            }
        }
        return num;
    }
};