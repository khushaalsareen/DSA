class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<double>prefix(nums.size(),1);
        vector<double>suffix(nums.size(),1);
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1];
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = (prefix[i-1]==0?1:prefix[i-1])*nums[i];
        }
        for(int i = nums.size()-2;i>=0;i--){
            suffix[i] = (suffix[i+1]==0?1:suffix[i+1]) * nums[i];
        }
        int pmax = *max_element(prefix.begin(),prefix.end());
        int smax = *max_element(suffix.begin(),suffix.end());
        return max(pmax,smax);

    //    double prefixPro = 1;
    // double sufixPro = 1;
    // double maxi = INT_MIN;
    // int n = nums.size();
    
    // for (int i = 0; i < n; i++) {
    //     if (prefixPro == 0) prefixPro = 1;
    //     if (sufixPro == 0) sufixPro = 1;

    //     prefixPro *= nums[i];
    //     sufixPro *= nums[n - i - 1];

    //     maxi = max(maxi, max(sufixPro, prefixPro));
    // }
    
    // return maxi;
    }
};
 