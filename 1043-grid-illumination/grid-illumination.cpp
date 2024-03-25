class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> m1; // row mei kitne lamps
        unordered_map<int, int> m2; // column mei kitne lamps
        unordered_map<int, int> m3; // top left to bottom right diag mei kitne lamps
        unordered_map<int, int> m4; // top right to bottom left mei kinne lamps
        unordered_map<long long int, long long int> m5;

        for(int i=0;i<lamps.size();i++){
            int x = lamps[i][0];
            int y = lamps[i][1];
            m1[x]++;
            m2[y]++;
            m3[x-y]++;
            m4[x+y]++;
            m5[x*1LL*n+y]++;
        }
        vector<int> ans;
        vector<pair<int,int>>directions ={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{0,0}}; 
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0]; // row
            int y = queries[i][1]; // col
            if((m1.find(x)!=m1.end() && m1[x]>0) || (m2.find(y)!=m2.end() && m2[y]>0) || (m3.find(x-y)!=m3.end() && m3[x-y]>0) || (m4.find(x+y)!=m4.end() && m4[x+y]>0)){
                ans.push_back(1);
                for(int i=0;i<directions.size();i++){
                    int x1 = x + directions[i].first;
                    int y1 = y + directions[i].second;
                    if(x1>=0 && y1>=0 && x1<n && y1<n && m5.find(x1*1LL*n+y1)!=m5.end()){
                        int times = m5[x1*n+y1];
                        m1[x1]-=times;
                        m2[y1]-=times;
                        m3[x1-y1]-=times;
                        m4[x1+y1]-=times;
                        m5.erase(x1*1LL*n+y1);
                    }
                }
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;

    }
};