class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        int cnt = 0;
        int ele = -1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                ele = i;
            }
        }
        if(cnt == 1)
        return ele;
        return -1;
    }
};