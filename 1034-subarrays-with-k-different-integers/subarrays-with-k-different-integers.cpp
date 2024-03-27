class Solution {
public:
  int f(vector<int>&nums, int k){
    int i = 0;
        int j = 0;
        int cnt = 0;
        unordered_map<int,int>m;
        while(j<nums.size()){
            m[nums[j]]++; // subarray ending at index j
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
  }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return f(nums,k) - f(nums,k-1);
    }
};