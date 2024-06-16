class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int cnt = 0;
        for(int i=1;i<=2000;i++){
            if(m.find(i)==m.end()){
                cnt++;
                if(cnt==k)
                return i;
            }
        }
        return -1;
    }
};