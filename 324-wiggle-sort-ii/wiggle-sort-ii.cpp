class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==1)
        return;
        priority_queue<int>pq(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            nums[i] = pq.top();
            pq.pop();
        }
        for(int i=0;i<nums.size();i+=2){
            nums[i] = pq.top();
            pq.pop();
        }
    }
};