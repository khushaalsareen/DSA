class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       int i = 0;
       int j = 0;
       int len = 0;
       int maxLen = len;
       map<int,int>m;
       while(j<nums.size()){
            m[nums[j]]++;
            int lb = nums[j] - limit;
            int up = nums[j] + limit;
            auto it = (m.end());
            it--;
            int maxi = it->first;
            int mini = m.begin()->first;
            while(maxi>up || mini<lb){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                it = m.end();
                it--;
                maxi = it->first;
                mini = m.begin()->first;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
       } 
       return maxLen;
    }
};