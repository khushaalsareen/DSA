class Solution {
public:
    bool f(vector<int>&piles, int mid, int h){
        long long int time = 0;
        for(int i=0;i<piles.size();i++){
            time+= ceil(piles[i]/(mid*1.0));
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hour) {
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(f(piles,mid,hour))
            h = mid -1;
            else
            l = mid + 1;
        }
        return l;
    }
};