class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>m;
        m.insert({0,1});
        int psum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            psum+=nums[i];
            if(m.find(psum-goal)!=m.end()){
                cnt+=m[psum-goal];
            }
            m[psum]++;
        }
        return cnt;
    }
};