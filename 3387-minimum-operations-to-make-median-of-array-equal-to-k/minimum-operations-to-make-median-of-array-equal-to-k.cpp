class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ops = 0;
        sort(nums.begin(),nums.end());
        if(nums[nums.size()/2]==k){
            return 0*1LL;
        }
        int n = nums.size();
        ops+=abs(nums[n/2]-k);
        for(int i=0;i<n/2;i++){
            if(nums[i]>k)
            ops+=abs(nums[i]-k);
        }
        for(int i=n/2+1;i<n;i++){
            if(nums[i]<k){
                ops+=abs(nums[i]-k);
            }
        }
        return ops;
    }
};