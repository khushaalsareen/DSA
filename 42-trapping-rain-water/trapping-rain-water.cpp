class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n==2)
        return 0;
        int lmax = heights[0];
        int rmax = heights[n-1];
        int l = 1;
        int r = n-2;
        int cnt = 0;
        while(l<=r){
            // left is deciding factor
            if(lmax<=rmax){
                if(lmax<=heights[l])
                cnt+=0;
                else
                cnt+=lmax-heights[l];
                lmax = max(lmax,heights[l]);
                l++;
            }
            else{
                // right is deciding factor
                if(rmax<=heights[r])
                cnt+=0;
                else
                cnt+=rmax-heights[r];
                rmax = max(rmax,heights[r]);
                r--;
            }
        }
        return cnt;
    }
};