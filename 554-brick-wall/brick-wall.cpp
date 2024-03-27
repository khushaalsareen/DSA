class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>m;
        int maxi = 0;
        for(int i=0;i<wall.size();i++){
            int pc = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                pc = pc + wall[i][j];
                m[pc]++;
                maxi = max(maxi,m[pc]);
            }
        }
        return wall.size()-maxi;
    }
};