class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n);
        vector<int>lds(n);
        lis[0] = 1;
        lds[0] = 1;
        int res = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                lis[i] = 1;
                lds[i] = 1;
            }
            else if(nums[i]>nums[i-1]){
                lis[i] = 1 + lis[i-1];
                lds[i] = 1;
            }
            else{
                lis[i] = 1;
                lds[i] = 1 + lds[i-1];
            }
            res = max({res,lis[i],lds[i]});
        }
        for(auto it:lis)
        cout<<it<<" ";
        cout<<endl;
        for(auto it:lds)
        cout<<it<<" ";
        return res;
    }
};