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
        int sc = 0;
        int ec = n-1;
        while(sc<ec){
            for(int r=0;r<n;r++){
                swap(nums[r][sc],nums[r][ec]);
            }
            sc++;
            ec--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};