class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                int st = ans.back()[0];
                int ep = max(ans.back()[1],intervals[i][1]);
                ans[ans.size()-1][1] = ep; 
            }
        }
        return ans;
    }
};