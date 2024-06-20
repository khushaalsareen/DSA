class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int psum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i]; // prefix sum ending at index i
            if(psum == k){
                cnt++;
            }
            if(m.find(psum-k)!=m.end())
            cnt+=m[psum-k];
            m[psum]++;
        }
        return cnt;
    }
};