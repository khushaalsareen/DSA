class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int st = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            // here nums[i] = maxi and nums[st] = start
            while(nums[i]-nums[st]>2*k)
            st++;
            // now window from from A[st] ---- A[i] is valid
            ans = max(ans,i-st+1);
        }
        return ans;
    }
};