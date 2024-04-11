class Solution {
public:
   static bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.first==p2.first)
    return p1.second>p2.second;
    return p1.first<p2.first;
   }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int,int>>v;
        for(auto it: envelopes){
            v.push_back({it[0],it[1]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>dp(n,0);
        dp[0] = v[0].second;
        int ans = 1;
        for(int i=1;i<n;i++){
            int l = 0;
            int h = ans;
            while(l<h){
                int m = l+(h-l)/2;
                if(dp[m]<v[i].second){
                    l = m+1;
                }
                else{
                    h = m;
                }
            }
            dp[l] = v[i].second;
            if(l==ans)
            ans++;
        }
        return ans;
    }
};