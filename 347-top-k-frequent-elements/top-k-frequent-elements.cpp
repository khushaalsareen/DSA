class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:m){
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        while(!pq.empty()){
            pair<int,int> p =pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};