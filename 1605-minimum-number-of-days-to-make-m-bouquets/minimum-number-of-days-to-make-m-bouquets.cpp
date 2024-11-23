class Solution {
    bool f(int mid, vector<int>&nums, int m, int k){
        int cnt = 0;
        for(int i=0;i<nums.size();){
            int flower = 0;
            int j = i;
            bool var = false;
            while(j<nums.size() && flower < k && nums[j]<=mid){
                flower++;
                var = true;
                j++;
            }
            if(flower == k)
            cnt++;
            if(var)
            i = j;
            else
            i++;
        }
        return cnt>=m;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(n<m*1LL*k)
        return -1;

        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l + (h-l)/2;
            bool check = f(mid, nums, m, k);
            if(check){
                ans = mid;
                h = mid - 1;
            }else
                l = mid +1 ;
        }
        return ans;
    }
};