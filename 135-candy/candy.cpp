class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        if(mini == maxi)
        return n;
        vector<int>v(n);
        queue<pair<int,int>>q;
        if(nums[0]<=nums[1])
        q.push({0,1});
        if(nums[n-1]<=nums[n-2])
        q.push({n-1,1});
        for(int i=1;i<n-1;i++){
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
            q.push({i,1});
            else if(nums[i]<nums[i-1] && nums[i]==nums[i+1])
            q.push({i,1});
            else if(nums[i]==nums[i-1] && nums[i]==nums[i+1])
            q.push({i,1});
            else if(nums[i]==nums[i-1] && nums[i]<nums[i+1])
            q.push({i,1});
            else if(nums[i]==nums[i+1] && nums[i]<nums[i-1])
            q.push({i,1});
            
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int currIdx = p.first;
            int currCandy = p.second;
            v[currIdx] = currCandy;
            if(currIdx>0 && nums[currIdx]<nums[currIdx-1]){
                q.push({currIdx-1,currCandy+1});
            }
            if(currIdx<n-1 && nums[currIdx]<nums[currIdx+1]){
                q.push({currIdx+1,currCandy+1});
            }
            
        }
        int sum = 0;
        for(auto it:v){
            sum+=it;
        }
        return sum;
    }
};