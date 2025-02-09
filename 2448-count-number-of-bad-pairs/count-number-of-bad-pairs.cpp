class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long ans = 0;
       int n = nums.size();
       unordered_map<int,int>m;
       for(int i=0;i<n;i++){
        m[nums[i]-i]++;
       }
       long long cnt = 0;
       for(auto it:m){
        long long int val = it.second;
        if(val>1){
            cnt+=((val)*(val-1))/2;
        }
       }

       return (n*1LL*(n-1))/2- cnt ;
    }
};