class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s;
        for(auto it:deadends){
            s.insert(it);
        }

        unordered_set<string>visited;
        visited.insert("0000");
        queue<pair<string,int>>q;
        q.push({"0000",0});
        while(!q.empty()){
            pair<string,int> p  = q.front();
            q.pop();
            string &curr = p.first;
            int steps = p.second;
            if(curr == target && s.find(target)==s.end())
            return steps;
            if(s.find(curr)==s.end()){
            for(int i=0;i<4;i++){
                char ch = curr[i];
                int num = ch - '0';
                int inc = num+1;
                if(inc==10)
                inc = 0;
                int dec = num - 1;
                if(dec<0)
                dec= 9;
                string sbstr = curr.substr(0,i);
                string next = sbstr + to_string(inc) + curr.substr(i+1,4-sbstr.size()-1);
                string prev = sbstr + to_string(dec) + curr.substr(i+1,4-sbstr.size()-1);
                if(s.find(next)==s.end() and visited.find(next)==visited.end())
                {
                    q.push({next,steps+1});
                    visited.insert(next);
                }
                if(s.find(prev)==s.end() and visited.find(prev)==visited.end()){
                    q.push({prev,steps+1});
                    visited.insert(prev);
                }
            }
        }
        }
        return -1;
    }
};