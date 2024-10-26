class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            int missing = nums[mid]- (mid+1);
            if(missing < k)
            l = mid + 1;
            else
            h = mid - 1;
        }
        return k + l;
    }
};