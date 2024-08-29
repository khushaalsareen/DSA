class Solution {
public:
    bool f(int ind, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0)
        return true;
        if(ind == 0){
            return target == nums[ind];
        }
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        bool nottake = f(ind-1,target,nums,dp);
        bool take = false;
        if(nums[ind]<=target)
        take = f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take || nottake;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,false));
        // return f(n-1,target,stones,dp);
        vector<int>nums = stones;
        if(nums[0]<=target)
        dp[0][nums[0]] = true;
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum/2;target++){
                bool nottake = dp[ind-1][target];
            bool take = false;
            if(nums[ind]<=target)
            take = dp[ind-1][target-nums[ind]];// f(ind-1,target-nums[ind],nums,dp);
             dp[ind][target] = take || nottake;
            }
        }
        for(int i=sum/2;i>=0;i--){
            if(dp[n-1][i])
            return sum - (2 * i);
        }
        return 0;
    }
};