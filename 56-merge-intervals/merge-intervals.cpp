class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            // if ans is empty or curr start > last end
            if(ans.empty() || start>ans.back()[1]){
                ans.push_back({start,end});
            }
            else{
                ans.back()[1] = max(ans.back()[1],end);
            }
         }
         return ans;
    }
};