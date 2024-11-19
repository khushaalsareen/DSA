class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int>m;
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            m[nums[i]]++;
        }
        if(m.size()==k)
        ans = max(ans,sum);
        for(int i=k;i<n;i++){
            m[nums[i]]++;
            m[nums[i-k]]--;
            sum+=nums[i];
            sum-=nums[i-k];
            if(m[nums[i-k]]==0)
            m.erase(nums[i-k]);
            if(m.size()==k)
            ans = max(ans,sum);
        }
        return ans;
    }
};