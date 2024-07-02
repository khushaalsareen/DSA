class Solution {
public:
    static bool cmp(int x, int y){
        if(abs(x)==abs(y))
        return x>y;
        return abs(x)<abs(y);
    }
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[0];
    }
};