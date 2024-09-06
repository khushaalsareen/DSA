class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int num1 = -1e9;
        int num2 = -1e9;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1)
            cnt1++;
            else if(nums[i]==num2)
            cnt2++;
            else if(cnt1==0){
                num1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                num2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int f1 = 0;
        int f2 = 0;
        for(auto it:nums){
            if(it==num1)
            f1++;
            if(it==num2)
            f2++;
        }
        int n = nums.size();
        if(f1<=n/3 && f2<=n/3)
        return {};
        if(f1>n/3)
        ans.push_back(num1);
        if(f2>n/3)
        ans.push_back(num2);
        return ans;
    }
};