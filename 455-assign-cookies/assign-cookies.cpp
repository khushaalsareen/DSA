class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sweet) {
        int m = greed.size();
        int n = sweet.size();
        sort(greed.begin(),greed.end());
        sort(sweet.begin(),sweet.end());
        int idx = 0;
        int cnt = 0;
        int j = 0;
        while(idx < m && j<n){
            if(sweet[j]<greed[idx])
            j++;
            else{
                cnt++;
                j++;
                idx++;
            }
        }
        return cnt;
    }
};