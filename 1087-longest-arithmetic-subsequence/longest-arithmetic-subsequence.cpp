class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        vector<unordered_map<int,int>>v(n);
        //length of LAS ending at index i
        for(int i=1;i<n;i++){
            for(int j = i-1;j>=0;j--){
                int currDiff = nums[i] - nums[j];
                if(v[j].find(currDiff)!=v[j].end()){
                    int len = v[j].find(currDiff)->second;
                    res = max(res, 1 + v[j].find(currDiff)->second);
                    v[i].insert({currDiff,1+len});
                }
                else{
                    res = max(res,2);
                    v[i].insert({currDiff,2});
                }

            }
        }
        return res;
    }
};