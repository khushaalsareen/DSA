class Solution {
public:
    bool isPossible(int mid, vector<int>&nums, int m){
        int cnt = 1;
        int prev = 0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[prev])>=mid){
                cnt++;
                prev = i;
            }
        }
        if(cnt<m)
        return false;
        return true;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int l = 1;
        int h = nums[nums.size()-1] - nums[0];
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(mid,nums,m)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};