class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n,INT_MAX);
        vector<int>temp(n,INT_MAX);
        prices[src] = 0;
        temp[src] = 0;

        for(int i=1;i<=k+1;i++){
            for(int i=0;i<flights.size();i++){
                if(prices[flights[i][0]]==INT_MAX)
                continue;
                else{
                    if(prices[flights[i][0]] + flights[i][2]< temp[flights[i][1]]){
                         temp[flights[i][1]] = prices[flights[i][0]] + flights[i][2];
                    }
                }
            }
            prices = temp;            
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};