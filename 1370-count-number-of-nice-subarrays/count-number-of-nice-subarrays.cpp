class Solution {
public:
    int f(vector<int>&nums, int k){
        int cnt = 0;
        int i = 0;
        int j = 0;
        int num = 0;
        while(j<nums.size()){
            if(nums[j]%2 == 1)
            cnt++;
            while(cnt>k){
                if(nums[i]%2 == 1)
                cnt--;
                i++;
            }
           
            num+=j-i+1;
            j++;
        }
        cout<<num<<endl;
        return num;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return f(nums,k)-f(nums,k-1);
    }
};