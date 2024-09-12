class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
            break;
        }
        int temp = nums[0];
        while(temp!=slow){
            temp = nums[temp];
            slow = nums[slow];
        }
        return temp;
    }
};