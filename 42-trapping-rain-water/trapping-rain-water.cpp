class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int pmax[n],smax[n];
        pmax[0] =height[0];
        smax[n-1] =height[n-1];
        for(int i=1;i<n;i++){
            pmax[i] =max(pmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            smax[i] =max(smax[i+1],height[i]);
        }
        int ans= 0;
        for(int i=1;i<=n-2;i++){
            int max_left_ht =pmax[i-1];
            int max_right_ht=smax[i+1];
            int curr_height= height[i];
            int deciding_ht =min(max_left_ht,max_right_ht);
            if(deciding_ht <= curr_height)
            ans+=0;
            else
            ans+= deciding_ht - curr_height;
        }
        return ans;
    }
};