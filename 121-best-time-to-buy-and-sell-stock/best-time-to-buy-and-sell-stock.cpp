class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int pmin = prices[0];
        for(int i=1;i<n;i++){
            ans = max(ans,prices[i]-pmin);
            pmin = min(pmin,prices[i]);
        }
        return ans;
    }
};