class Solution {
public:
    bool isPossible(int mid, vector<int>&piles, int h){
       long long int time = 0;
        for(auto &it:piles){
            time+=ceil(it/(mid*1LL*1.0));
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            bool check = isPossible(mid,piles,hr);
            if(check){
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};