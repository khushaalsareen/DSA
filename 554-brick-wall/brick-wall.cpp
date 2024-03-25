class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>m;
        int maxi = INT_MIN;
        for(int i=0;i<wall.size();i++){
            int pc = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                pc+=wall[i][j];
                m[pc]++;
                maxi = max(maxi,m[pc]);
            }
        }
        return maxi == INT_MIN ? wall.size() : wall.size() - maxi;
    }
};