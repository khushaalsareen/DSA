class Solution {
public:
        
       
    int getLargestOutlier(vector<int>& nums) {
        
        int  n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
       int sum = 0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        int ans = -1e9;
        for(int i=0;i<n;i++){
            int currSum = sum - nums[i];
            if(currSum%2 == 0 && m.find(currSum/2)!=m.end()){
                int freq = m[currSum/2];
                if(currSum/2 != nums[i] || m[currSum/2] >1)
                    ans = max(ans,nums[i]);
            }
        }
        return ans;
        
    }
};