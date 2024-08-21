class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans  = -1e9;
        while(i<j){
            ans = max(ans,min(height[j],height[i])*(j-i));
            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return ans;
    }
};