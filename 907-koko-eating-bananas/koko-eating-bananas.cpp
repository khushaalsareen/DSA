class Solution {
public:
    bool isPossible(long long k, vector<int>&piles, int h){
        long long int time = 0;
        for(auto it:piles){
            time+= ceil((it*1.0)/k);
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hour) {
        long long int l = 1;
        long long int sum = 0;
        for(auto it:piles){
            sum+=it;
        }
        long long int h = sum;
        long long int mid;
        long long int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(mid,piles,hour)){
                ans = mid;
                h = mid-1;
            }
            else
            l = mid + 1;
        }
        return ans;
    }
};