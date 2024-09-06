class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool>m;
        for(auto it:nums)
        m[it]=true;
        for(int i=0;i<n;i++){
            if(m.find(nums[i]-1)!=m.end())
            m[nums[i]] = false;
        }
        int maxLen = 0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second == true){
                int len = 0;
                int num = it->first;
                while(m.find(num)!=m.end()){
                    len++;
                    num+=1;
                }
                maxLen = max(maxLen,len);
            }
        }
        return maxLen;
    }
};