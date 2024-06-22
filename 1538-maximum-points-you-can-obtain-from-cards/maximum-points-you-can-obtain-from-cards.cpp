class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        vector<int>psum(nums.size(),0);
        vector<int>ssum(nums.size(),0);
        psum[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        psum[i] = nums[i] + psum[i-1];
        ssum[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            ssum[i] = ssum[i+1] + nums[i];
        }
        int ans = max(psum[k-1],ssum[nums.size()-k]);
        for(int i = 1;i<k;i++){
            int frontCards = i;
            int backCards = k - i;
            int pIdx = frontCards - 1;
            int sIdx = nums.size()-backCards;
            ans = max(ans, psum[pIdx] + ssum[sIdx]);
        }
        return ans;
    }
};