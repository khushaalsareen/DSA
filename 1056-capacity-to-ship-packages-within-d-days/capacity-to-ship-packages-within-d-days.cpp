class Solution {
public:
    bool f(vector<int>& weights,int mid, int days){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
                // i++;
            }
            else{
                cnt++;
                sum = weights[i];
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = 0;
        for(auto it:weights)
        h+=it;
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(f(weights,mid,days))
            h = mid - 1;
            else
            l = mid + 1;
        }
        return l;
    }
};