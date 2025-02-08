class Solution {
public:
    double bfs(string start, string end,unordered_map<string,vector<pair<string,double>>>&m ){
        queue<pair<string,double>>q;
        set<string>s;
        if (m.find(start) == m.end() || m.find(end) == m.end()) return -1.0;
           if (start == end) return 1.0;
        q.push({start,1});
        s.insert(start);
        while(!q.empty()){
            pair<string,double> p = q.front();
            q.pop();
            string currString = p.first;
            double currVal = p.second;
            if(currString == end)
            return currVal;
            for(auto it:m[currString]){
                if(s.find(it.first)==s.end()){
                    s.insert(it.first);
                    q.push({it.first,currVal * it.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>m;
        for(int i=0;i<n;i++){
            vector<string>&it = equations[i];
            string &u = it[0];
            string &v = it[1];
            m[u].push_back({v,values[i]});
            double reci = 1/values[i];
            m[v].push_back({u,reci});
        }
        int q = queries.size();
        for(auto it:queries){
            double res = bfs(it[0],it[1],m);
            ans.push_back(res);
        }
        return ans;
    }
};