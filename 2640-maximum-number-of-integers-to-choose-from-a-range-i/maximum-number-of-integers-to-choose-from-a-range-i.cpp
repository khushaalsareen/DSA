class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        int size = nums.size();
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end() && sum+i<=maxSum)
            {
                cnt++;
                sum+=i;
            }
        }
        return cnt;
    }
};