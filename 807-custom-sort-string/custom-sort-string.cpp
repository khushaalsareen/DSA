class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        string ans = "";
        for(int i=0;i<order.size();i++){
            if(m.find(order[i])==m.end())
            continue;
            else{
                auto it = m.find(order[i]);
                int freq = it->second;
                while(freq--){
                    ans.push_back(it->first);
                }
                m.erase(it);
            }
        }
        while(!m.empty()){
            auto it = m.begin();
            int freq = it->second;
            while(freq--){
                ans.push_back(it->first);
            }
            m.erase(it);
        }
        return ans;
    }
};