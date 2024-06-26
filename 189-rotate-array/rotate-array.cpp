class Solution {
public:
    void reverse(vector<int>&nums, int s, int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int n=nums.size();
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};