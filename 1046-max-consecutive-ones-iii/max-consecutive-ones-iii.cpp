class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = k;
        while(j<n){
            if(nums[j]==0)
            cnt--;
            while(cnt<0){
                if(nums[i]==0)
                cnt++;
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
        
    }
};