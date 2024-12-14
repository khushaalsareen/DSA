class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int>m;
        int i = 0;
        int j = 0;
        long long ans = 0;
        while(j<n){
            m[nums[j]]++;
            auto itStart = m.begin();
            auto itEnd = m.rbegin();
            int mini = itStart->first;
            int maxi = itEnd->first;
            while(abs(maxi-mini)>2){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                i++;
                mini = m.begin()->first;
                maxi = m.rbegin()->first;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};