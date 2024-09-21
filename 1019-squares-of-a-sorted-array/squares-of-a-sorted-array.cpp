class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                idx = i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        
        int j = idx - 1;
        vector<int>ans;
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        while(j>=0 && idx<n){
            if(nums[idx]>nums[j]){
                ans.push_back(nums[j]);
                j--;
            }
            else{
                ans.push_back(nums[idx]);
                idx++;
            }
        }
        while( idx<n){
            ans.push_back(nums[idx]);
                idx++;
        }
        while(j>=0){
            ans.push_back(nums[j]);
                j--;
        }
        return ans;
    }
};