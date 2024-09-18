class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h){
        long long int tot_time = 0;
        for(auto it:piles){
            tot_time += ceil(it/(mid*1.0))*1LL;
        }
        return tot_time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(mid,piles,hrs)){
                ans = mid;
                h = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
};