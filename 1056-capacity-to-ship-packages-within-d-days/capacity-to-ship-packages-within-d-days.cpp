class Solution {
public:
    bool f(int m, vector<int>&weights, int days){
        if(m<*max_element(weights.begin(),weights.end()))
        return false;
        int cnt = 1;
        int i = 1;
        int wt = weights[0];
        while(i<weights.size()){
            if(i<weights.size() && wt+weights[i]<=m)
              {
                wt+=weights[i];
                i++;
              }
            else if(i<weights.size())
            {
                cnt++;
                wt = weights[i];
                i++;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int sum = 0;
        for(auto it: weights)
        sum+=it;
        int h = sum;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            cout<<endl<<m;
            if(f(m,weights,days)){
                if( f(m-1,weights,days))
                h = m-1;
                else
                return m;
            }
            else{
                l = m+1;
            }
        }
        return -1;
    }
};