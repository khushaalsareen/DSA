class Solution {
public:
    void transpose(vector<vector<int>>&nums){
        int n =nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<k){
                swap(nums[i][j],nums[i][k]);
                j++;
                k--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};