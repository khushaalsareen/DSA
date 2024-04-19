struct helper
{
    bool operator()(const pair<string,int> &a, const pair<string,int> &b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
    
        priority_queue<pair<string,int>, vector<pair<string,int>> , helper>pq;
        unordered_map<string,int>m;

        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(auto &a: m){
            pq.push({a.first,a.second});
            if(pq.size()>k)
            pq.pop();
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};