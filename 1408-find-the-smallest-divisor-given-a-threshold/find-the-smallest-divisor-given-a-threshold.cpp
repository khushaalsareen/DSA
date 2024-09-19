class Solution {
public:
    bool check(int m, vector<int>&nums, int threshold){
        int sum = 0;
        for(auto it:nums){
            sum+=ceil(it/(m*1.0));
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int m;
        int ans;
        while(l<=h){
            m = l+(h-l)/2;
            if(check(m,nums,threshold)){
                ans = m;
                h = m -1;
            }
            else
            l = m+1;
        }
        return ans;

    }
};