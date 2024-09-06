class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        /* int one=0,zero=0; */
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) sum++;
            else
            sum--;
            if(sum==0)
            ans=max(ans,i+1);
            if(m.find(sum)!=m.end())
            ans=max(ans,i-m[sum]);
            if(m.find(sum)==m.end())
            m[sum]=i;
        }
        return ans;
    }
};