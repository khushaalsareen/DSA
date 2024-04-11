class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        int ans = 1;
        for(int i=1;i<n;i++){
            int l = 0;
            int h = ans;
            while(l<h){
                int m = l+(h-l)/2;
                if(dp[m]<nums[i]){
                    l = m+1;
                }
                else{
                    h = m;
                }
            }
            dp[l] = nums[i];
            if(l==ans)
            ans++;
        }
        return ans;
    }
};