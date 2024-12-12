class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n  = gifts.size();
        
        priority_queue<int>pq;
        for(auto it:gifts)
        pq.push(it);
        long long ans = 0;
        while(k--){
            int ele = pq.top();
            pq.pop();
            pq.push(sqrt(ele));
        }
        while(!pq.empty()){
            ans +=pq.top();
            pq.pop();
        }
        return ans;
    }
};