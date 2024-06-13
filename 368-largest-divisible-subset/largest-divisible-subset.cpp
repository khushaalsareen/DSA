class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
      

        vector<int>lis(nums.size(),1);
        vector<int>hash(nums.size());
        for(int i=0;i<nums.size();i++)
        hash[i] = i;

        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(lis[i]<1+lis[j]){
                        lis[i] = 1+lis[j];
                        hash[i] = j;
                    }
                }
            }
        }
        int maxi = -1e9;
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(lis[i]>maxi){
                maxi = lis[i];
                idx= i;
            }
        }

        ans.push_back(nums[idx]);
        while(hash[idx]!=idx){
            ans.push_back(nums[hash[idx]]);
            idx = hash[idx];
        }
        return ans;
    }

};