class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
        return 0;
        vector<int>pmax(n);
        vector<int>smax(n);
        pmax[0] = height[0];
        for(int i=1;i<n;i++){
            pmax[i] = max(height[i],pmax[i-1]);
        }
        smax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            smax[i] = max(height[i],smax[i+1]);
        }
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            int dec_ht = min(pmax[i-1],smax[i+1]);
            if(dec_ht<=height[i])
            cnt+=0;
            else
            cnt+= dec_ht - height[i];
        }
        return cnt;
    }
};