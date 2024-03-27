class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it:nums)
        s.insert(it);

        int ans = 0;
        for(auto it = s.begin();it!=s.end();it++){
            int curr = *it;
            
            if(s.find(curr-1)==s.end()){ //possibly first number of some sequnec
                int currLen = 1;
                long int nextEle = curr + 1;
                while(s.find(nextEle)!=s.end()){
                    currLen++;
                    nextEle = nextEle + 1;
                }
                ans = max(ans,currLen);
            }
        }
        return ans;
    }
};