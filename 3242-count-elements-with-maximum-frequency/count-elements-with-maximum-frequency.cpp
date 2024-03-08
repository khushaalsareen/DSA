class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxCnt = 0;
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            maxCnt = max(maxCnt,it->second);
        }
        int cnt = 0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second == maxCnt)
            cnt++;
        }
        return cnt*maxCnt;
    }
};