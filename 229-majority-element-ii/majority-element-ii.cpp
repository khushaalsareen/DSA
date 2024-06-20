class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = -1e9-1;
        int maj2 = -1e9-1;
        int freq1 = 0;
        int freq2 = 0;
        int idx = 0;
        while(idx<nums.size()){
            if(maj1==nums[idx   ])
            freq1++;
            else if(maj2==nums[idx])
            freq2++;
            else if(freq1 == 0){
                maj1 = nums[idx];
                freq1 = 1;
            }
            else if(freq2 == 0){
                maj2 = nums[idx];
                freq2 = 1;
            }
            else{
                freq1--;
                freq2--;
            }
            idx++;
        }
        int check1 =0;
        int check2 = 0;
        for(auto it:nums){
            if(it==maj1)
            check1++;
            if(it==maj2)
            check2++;
        }
        vector<int>ans;
        if(check1>n/3)
        ans.push_back(maj1);
        if(check2>n/3)
        ans.push_back(maj2);
        return ans;
    }
};