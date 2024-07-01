class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int k = 3;
        int n = arr.size();
        if(n<3)
        return false;
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(arr[i]%2 == 1)
            cnt++;
        }
        if(cnt==3)
        return true;
        for(int i=k;i<n;i++){
            if(arr[i]%2 == 1)
            cnt++;
            if(arr[i-k]%2 == 1)
            cnt--;
            if(cnt==3)
            return true;
        }
        return false;
    }
};