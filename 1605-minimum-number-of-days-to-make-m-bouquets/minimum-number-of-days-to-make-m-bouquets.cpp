class Solution {
public:
    // can you make m bouquets within mid days
    int f(int mid, vector<int>&nums, int m, int k){
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        for(;i<k;i++){
            if(nums[i]>mid)
            break;
        }
        if(i==k)
        cnt++;
        i = i==k? k: i+1;
        while(i<n){
            int j = i;
            int idx = i+k;
            for(;j<i+k && j<n ;j++){
                if(nums[j]>mid)
                {
                    idx = j+1;
                    break;
                }
            }
            if(idx == j)
            cnt++;
            i= idx ;
        }
        return cnt>=m;
    }
    int minDays(vector<int>&nums, int m, int k) {
        int n = nums.size();
        if(n<m*1LL*k)
        return -1;
        int l = *min_element(nums.begin(),nums.end());
        int h = *max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(l<=h){
            mid = l+(h-l)/2;
            cout<<mid<<endl;
            if(f(mid,nums,m,k)){
                ans = mid;
                h = mid - 1;
            }
            else
            l = mid +1;
        }
        return ans;
    }
};