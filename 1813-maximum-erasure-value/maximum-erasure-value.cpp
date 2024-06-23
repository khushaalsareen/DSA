class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int score = 0;
        int maxScore = 0;
        unordered_map<int,int>m;
        while(j<n){
            score+=nums[j];
            m[nums[j]]++;
            while(m[nums[j]]>1){
                score-=nums[i];
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                i++;
            }
            maxScore = max(maxScore,score);
            j++;
        }
        return maxScore;
    }
};