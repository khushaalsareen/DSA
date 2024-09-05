class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int j;
        bool flag = false;
        while(i>0){
            if(nums[i]>nums[i-1]){
                j = i-1;
                flag = true;
                break;
            }
            i--;
        }
        if(flag == false)
        {
            int x1 = 0;
            int x2 = n-1;
            while(x1<x2){
                swap(nums[x1],nums[x2]);
                x1++;
                x2--;
            }

        }
        else{
            int idx = -1;
            for(int k = j+1;k<n;k++){
                if(nums[k]>nums[j]){
                    idx = k;
                }
                else
                break;
            }
            swap(nums[j],nums[idx]);
            reverse(nums.begin()+j+1,nums.end());
        }
    }
};