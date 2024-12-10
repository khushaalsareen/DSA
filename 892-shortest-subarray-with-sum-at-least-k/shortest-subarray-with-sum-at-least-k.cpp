class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long int>psum(n);
        psum[0] = nums[0]*1LL;
        for(int i=1;i<n;i++){
            psum[i] = psum[i-1] + nums[i];
        }
        int minLen = 1e9;
        deque<pair<long long int,int>>dq;
        dq.push_back({0,-1});
        for(int i=0;i<n;i++){
            
            while(!dq.empty() && ((psum[i]-dq.front().first)>=k)){
        
                minLen = min(minLen,i-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && psum[i]<=dq.back().first)
            dq.pop_back();
            dq.push_back({psum[i],i});
        }
        return minLen == 1e9? -1 : minLen;
    }
};
