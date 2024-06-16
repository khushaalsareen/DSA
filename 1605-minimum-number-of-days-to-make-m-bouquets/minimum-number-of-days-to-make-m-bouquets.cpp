class Solution {
public:
    // is it possible to make m bouquets in mid days where each bouquet must have k consecutive flowers
    bool f(vector<int>&bloomDay, int mid, int m, int k){
        int cntBouquets = 0;
        int cntFlowers = 0;
        int prev = 0;
        if(bloomDay[0]<=mid)
        {prev = 1;
         cntFlowers++;
        }
        if(cntFlowers == k) {cntBouquets++;
        cntFlowers = 0;
        }
        if(cntBouquets == m)
        return true;
        for(int i = 1;i<bloomDay.size();i++){
            int curr = 0;
            if(bloomDay[i]>mid){
                curr = 0;
                cntFlowers = 0;
            }
            else{
                curr = prev + 1;
                cntFlowers++;
                if(cntFlowers == k){
                    cntBouquets++;
                    cntFlowers = 0;
                    if(cntBouquets == m)
                    return true;
                }
            }
            prev = curr;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int check = m*1LL*k;
        if(check>bloomDay.size())
        return -1;

        long long int l= *min_element(bloomDay.begin(),bloomDay.end());
        long long int h = *max_element(bloomDay.begin(),bloomDay.end());
        long long int mid;
        while(l<=h){
            mid = l+(h-l)/2;
            if(f(bloomDay,mid,m,k))
            h = mid-1;
            else
            l = mid + 1;
        }
        return l;
    }
};