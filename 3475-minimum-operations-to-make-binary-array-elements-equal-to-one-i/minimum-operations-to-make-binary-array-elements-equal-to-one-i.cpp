class Solution {
public:
    int f(int mid, vector<int>&nums){
        int sum = 0;
        for(auto it:nums)
        sum+=it;
        if(sum == nums.size())
        return 0;
        int cnt = 0;
        for(int i=0;i<=nums.size()-3;i++){
            if(nums[i]==0){
                cnt++;
                nums[i] = 1;
                sum++;
                if(nums[i+1]==1){
                    nums[i+1]=  0;
                    sum--;
                }
                else{
                    sum++;
                    nums[i+1] = 1;
                }
                if(nums[i+2]==1){
                    sum--;
                    nums[i+2] = 0;
                }else{
                    sum++;
                    nums[i+2] = 1;
                }
            }
        if(sum == nums.size())
        return cnt;
        }
        
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 2;
        int mid;
        int ans = -1;
        
        return f(0,nums);
    }
};