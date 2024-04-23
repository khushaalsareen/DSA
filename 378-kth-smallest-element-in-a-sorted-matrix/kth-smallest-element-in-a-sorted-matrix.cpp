struct comp {
    bool operator()(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2){
            return p1.first>p2.first;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp>pq;
        pq.push({matrix[0][0],{0,0}});
        int cnt = 0;
        int val = 0;
        set<pair<int,int>>s;
        s.insert({0,0});
        while(!pq.empty() && cnt!=k){
            pair<int,pair<int,int>> p =pq.top();
            pq.pop();
            val = p.first;
            cnt++;
            int i = p.second.first;
            int j = p.second.second;
            
            if(i+1<matrix.size() && s.find({i+1,j})==s.end())
            {
                pq.push({matrix[i+1][j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(j+1<matrix.size() && s.find({i,j+1})==s.end()){
                pq.push({matrix[i][j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        return val;
    }
};