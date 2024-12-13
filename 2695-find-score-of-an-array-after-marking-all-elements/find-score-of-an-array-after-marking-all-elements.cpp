class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long ans = 0;
        unordered_set<int>s;
        while(!pq.empty()){
            pair<int,int> p  = pq.top();
            pq.pop();
            int ele= p.first;
            int idx = p.second;
            if(s.find(idx)==s.end()){
                s.insert(idx);
                ans+=ele;
                s.insert(idx+1);
                s.insert(idx-1);
            }
        }
        return ans;
    }
};