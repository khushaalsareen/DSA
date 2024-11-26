class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        int m = nums.size();
        int n = nums[0].size();
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                ans.push_back(nums[top][i]);
            }
            top++;
            if(left<=right && top<=bottom){
            for(int i=top;i<=bottom;i++){
                ans.push_back(nums[i][right]);
            }
            right--;
            }
            if(left<=right && top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
            }
            if(left<=right && top<=bottom){
            for(int i=bottom;i>=top;i--){
                ans.push_back(nums[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};