class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt =0;
        int currProduct = 1;
        while(j<nums.size()){
            currProduct*=nums[j];
            while(i<=j && currProduct>=k){
                currProduct/=nums[i++];
            }
            if(i<=j)
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};