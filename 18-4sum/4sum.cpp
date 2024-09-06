class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;){
            // int three = target - nums[i];
            for(int j=i+1;j<n;){
                // int two = three - nums[j];
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long int sum = nums[i]*1LL + nums[j] + nums[k] + nums[l];
                    if(sum<target)
                    k++;
                    else if(sum>target)
                    l--;
                    else{
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};