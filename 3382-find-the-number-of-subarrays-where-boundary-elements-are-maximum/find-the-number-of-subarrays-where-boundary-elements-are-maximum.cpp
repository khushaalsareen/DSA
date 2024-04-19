class Solution {
public:
    long long f(int ele, int greaterIdx, vector<int>&v){
        
        int l = 0;
        int h = v.size()-1;
        int m;
        while(l<h){
            m = l+(h-l)/2;
            if(v[m]<=greaterIdx)
                l = m+1;
            else
                h = m;
        }
        return v.size() - l;
    }
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        stack<int>s;
        s.push(n-1);
        vector<int>PGE(n,-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && nums[i]>nums[s.top()]){
                PGE[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
            int greaterIdx = PGE[i];
            if(greaterIdx == -1)
                ans+=m[nums[i]].size();
            else{
            long long int cnt = f(nums[i],greaterIdx,m[nums[i]]);
            ans +=cnt;
            }
        }
        return ans;
    }
};