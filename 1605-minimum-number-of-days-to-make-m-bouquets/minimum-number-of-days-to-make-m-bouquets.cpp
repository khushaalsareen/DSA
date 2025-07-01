class Solution {
    int f(vector<int>&nums, int mid,int k){
        int n = nums.size();
        int cnt = 0;
        int flowers = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                // it will bloom
                flowers++;
                if(flowers==k)
                {cnt++;
                flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        return cnt;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(m*1LL*k>n)
        return -1;

        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int ans;
        while(l<=h){
            int mid = l+(h-l)/2;
            // can I maake at least m bouquets having k flowers each in mid days
            // no of bouquets I can make
            int cnt = f(nums,mid,k);
            if(cnt<m){
                l = mid + 1;
            }
            else{
                ans = mid;
                h = mid-1;
            }
        }
        return ans;
    }
};