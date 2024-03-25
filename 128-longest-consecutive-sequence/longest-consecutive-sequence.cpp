class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it: nums){
            s.insert(it);
        }
        int ans = 0;
        for(auto it = s.begin();it!=s.end();it++){
            int currElement = *it;
            if(s.find(currElement-1)==s.end()){
                // first element of sequence
                int len = 1;
                int nextElement = currElement + 1;
                while(s.find(nextElement)!=s.end()){
                    len++;
                    nextElement++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};