class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();){
            // first value is nums[i];
            int f = nums[i];
            for(int j=i+1;j<nums.size();){
                // second value is nums[j]
                int s = nums[j];
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    if(f + s*1LL + nums[k] + nums[l]>target){
                        l--;
                    }
                    else if(f*1LL + s + nums[k] + nums[l]<target){
                        k++;
                    }
                    else{
                        vector<int>temp = {f,s,nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<nums.size() && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};