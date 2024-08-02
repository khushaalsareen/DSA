class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        v = nums;
        for(int i = 0;i<n;i++){
            v.push_back(nums[i]);
        }
        int cnt = 0;
        for(auto it:nums){
            if(it == 1)
            cnt++;
        }
        int zeroes = 0;
        int ans = 1e9;
        for(int i=0;i<cnt;i++){
            if(v[i]==0)
            zeroes++;
        }
        ans = min(ans,zeroes);
        for(int i=cnt;i<v.size();i++){
            if(v[i]==0)
            zeroes++;
            if(v[i-cnt]==0)
            zeroes--;
            ans = min(ans,zeroes);
        }
        return ans;
    }
};