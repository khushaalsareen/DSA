class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        int n=nums.size();
        int i=0;
        int j;
        for(;i<n;i++){
            if(nums[i]>=0)
            break;
        }
        j=i-1;
        while(j>=0 && i<n){
            if(nums[i]*nums[i]<=nums[j]*nums[j]){
                answer.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                answer.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        while(i<n){
            answer.push_back(nums[i]*nums[i]);
                i++;
        }
        while(j>=0){
            answer.push_back(nums[j]*nums[j]);
                j--;
        }
        return answer;
    }
};