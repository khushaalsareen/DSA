class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int i = 0;
        int j = 0 ;
        int currProduct = 1;
        while(j<nums.size()){
            if(currProduct*nums[j]<k){
                currProduct*=nums[j];
                cnt+=j-i+1;
                j++;
            }
            else{
                if(i!=j)
                currProduct/=nums[i];
                i++;
                if(i>j)
                j++;
            }
        }
        return cnt;
    }
};