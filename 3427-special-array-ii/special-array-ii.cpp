class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>maxReach(n);
        int i = 0;
        int j = 0;
        for(;i<n;i++){
            if(i>j)
            j = i;
            //max reachable for every index i
            while(j<n-1 && nums[j]%2 != nums[j+1]%2){
                j++;
            }
            maxReach[i] = j;
            
        }
        vector<bool>ans;
        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            ans.push_back(r<=maxReach[l]);
        }
        return ans;
    }
};