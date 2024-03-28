class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(j<nums.size()){
            m[nums[j]]++;     // subarray ending at index j
            while(i<=j && m[nums[j]]>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                i++;
            }
            cnt = max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};