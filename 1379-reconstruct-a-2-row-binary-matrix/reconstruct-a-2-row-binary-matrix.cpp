class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int m = 2;
        int n = colsum.size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int sum = 0;
        for(auto it:colsum)
            sum+=it;

        if(sum != upper+ lower)
        return {};

        int curr_row0_sum = 0;
        int curr_row1_sum = 0;
        for(int c=0;c<colsum.size();c++){
            if(colsum[c]==0){
                ans[0][c] = 0;
                ans[1][c] = 0;
            }
            else if(colsum[c]==2){
                ans[0][c] = 1;
                curr_row0_sum++;
                ans[1][c] = 1;
                curr_row1_sum++;
            }
        
        }
        int diff_row0_sum = upper - curr_row0_sum;
        int diff_row1_sum = lower - curr_row1_sum;
        for(int c = 0;c<n;c++){
           if(ans[0][c]==-1 && ans[1][c]==-1){
            if(diff_row0_sum>0){
                ans[0][c] = 1;
                diff_row0_sum--;
            }
            else{
                ans[1][c] = 1;
                diff_row1_sum--;
            }
           }
        }
        int sum_upper = 0;
        int sum_lower = 0;
        for(int r = 0;r<2;r++){
            for(int c = 0;c<n;c++){
                if(ans[r][c]==-1)
                    ans[r][c] = 0;
                if(r==0 && ans[r][c]==1)
                sum_upper++;
                else if(r==1 && ans[r][c]==1)
                sum_lower++;
            }

        }
        if(sum_upper != upper || sum_lower != lower)
        return {};
        return ans;
    }
};