class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int>m1; // row
        unordered_map<int,int>m2; // col
        unordered_map<int,int>m3; // left diag
        unordered_map<int,int>m4; // rt diag
        unordered_map<long long int,int>m5; // one cell
        for(int i=0;i<lamps.size();i++){
            int r = lamps[i][0];
            int c = lamps[i][1];
            m1[r]++;
            m2[c]++;
            m3[r-c]++;
            m4[r+c]++;
            m5[r*1LL*n+c]++;
        }
        vector<int>ans;
        vector<pair<int,int>>directions = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{0,0}};
        for(int i=0;i<queries.size();i++){
            int currX = queries[i][0];
            int currY = queries[i][1];
            if((m1.find(currX)!=m1.end() && m1[currX]>0) || (m2.find(currY)!=m2.end() && m2[currY]>0) || (m3.find(currX-currY)!=m3.end() && m3[currX-currY]>0) || (m4.find(currX+currY)!=m4.end() && m4[currX+currY]>0)){
                ans.push_back(1);
                for(int j=0;j<directions.size();j++){
                    int x1 = currX + directions[j].first;
                    int y1 = currY + directions[j].second;
                    if(x1>=0 && y1>=0 && x1<n && y1<n && m5.find(x1*1LL*n+y1)!=m5.end())
                    {
                    int times = m5[x1*1LL*n+y1];
                    m5.erase(x1*1LL*n+y1);
                     m1[x1]-=times;
                     m2[y1]-=times;
                     m3[x1-y1]-=times;
                     m4[x1+y1]-=times;
                    }
                }
            }
            else
            ans.push_back(0);
        }
        return ans;
    }
};