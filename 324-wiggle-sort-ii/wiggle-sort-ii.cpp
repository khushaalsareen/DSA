class Solution {
public:
    static bool cmp(int x, int y){
        return x>y;
    }
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return;
        sort(nums.begin(),nums.end(),cmp);
        vector<int> ans;
        ans = nums;
        int j = 0;
        for(int i=1;i<n;i+=2){
            nums[i] = ans[j];
            j++;
        }
        
        for(int i=0;i<n;i+=2){
            nums[i] = ans[j];
            j++;
        }
        
    }
};