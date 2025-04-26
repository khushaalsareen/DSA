class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        int m = nums.size();
        int n = nums[0].size();
        int tr = 0;
        int br = m-1;
        int lc = 0;
        int rc = n-1;
        while(tr<=br && lc<=rc){
            // print tr
            if(tr<=br){
            for(int c = lc;c<=rc;c++){
                ans.push_back(nums[tr][c]);
            }
            tr++;
            }
            // print rc
            if(lc<=rc)          
            {for(int r = tr;r<=br;r++){
                ans.push_back(nums[r][rc]);
            }
            rc--;
            }
            // print br
            if(tr<=br){
            for(int c = rc;c>=lc;c--){
                ans.push_back(nums[br][c]);
            }
            br--;
            }
            // print lc
            if(lc<=rc){
            for(int r = br;r>=tr;r--){
                ans.push_back(nums[r][lc]);
            }
            lc++;
            }
        }
        return ans;
    }
};