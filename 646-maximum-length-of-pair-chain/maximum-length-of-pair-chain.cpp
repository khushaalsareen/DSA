class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        int maxi = 1;
        vector<int>LIS(n,1);
        for(int i=0;i<n;i++){
            int s2 = pairs[i][0];
            int e2 = pairs[i][1];
            for(int j=i-1;j>=0;j--){
                int s1 = pairs[j][0];
                int e1 = pairs[j][1];
                if(e1<e2 && e1<s2)
                LIS[i] = max(LIS[i],1 + LIS[j]);
            }
            maxi = max(maxi,LIS[i]);
        }
        return maxi;
    }
};