class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,bool>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        // created starting points
        for(int i=0;i<n;i++){
            if(m.find(nums[i]-1)!=m.end()){
                m[nums[i]] = false;
            }
        }
        int len = 0;
        int maxLen = 0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)!=m.end())
            m[nums[i]] = false;
            else{
                len = 1;
                int ele = nums[i]+1;
                while(m.find(ele)!=m.end()){
                    len++;
                    ele++;
                }
                maxLen = max(maxLen,len);
               
            }
        }
        return maxLen;
    }
};