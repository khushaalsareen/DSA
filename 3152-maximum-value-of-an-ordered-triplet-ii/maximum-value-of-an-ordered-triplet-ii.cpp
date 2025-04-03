class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
      int n = nums.size();
      vector<int>pmax(n);
      vector<int>smax(n);
      pmax[0] = nums[0];
      for(int i=1;i<n;i++){
        pmax[i] = max(pmax[i-1],nums[i]);
      }   
      smax[n-1] = nums[n-1];
      for(int i=n-2;i>=0;i--){
        smax[i] = max(smax[i+1],nums[i]);
      }
      vector<int>pmin(n);
      vector<int>smin(n);
      pmin[0] = nums[0];
      for(int i=1;i<n;i++)
        pmin[i] = min(pmin[i-1],nums[i]);
      smin[n-1] = nums[n-1];
      for(int i=n-2;i>=0;i--)
        smin[i] = min(smin[i+1],nums[i]);

      long long ans = 0;
      for(int m=1;m<n-1;m++){
        long long v1 = (pmax[m-1]-nums[m])*1LL*smax[m+1];
        
        ans = max({ans,v1});
      }
      return ans;
    }
};