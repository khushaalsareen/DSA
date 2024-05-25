class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        if(nums.size()==1){
            int len = queries.size();
            vector<bool>v(len,true);
            return v;
        }
        vector<int>freq(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2 == 0 && nums[i+1]%2 == 0)
                freq[i+1] = 1;
            else if(nums[i]%2 && nums[i+1]%2)
                freq[i+1] = 1;
        }
        for(int i=1;i<freq.size();i++){
            freq[i] = freq[i-1] + freq[i];
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int idx1 = queries[i][0];
            int idx2 = queries[i][1];
            if(freq[idx1]!=freq[idx2])
            ans.push_back(false);
            else
            ans.push_back(true);
        }
        return ans;
    }
};