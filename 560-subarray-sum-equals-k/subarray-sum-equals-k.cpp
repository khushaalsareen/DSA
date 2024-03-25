class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int psum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            psum+=nums[i];
            if(psum==k){
                cnt++;
            }
            if(m.find(psum-k)!=m.end())
            cnt+=m[psum-k];
            m[psum]++;
        }
        return cnt;
    }
};