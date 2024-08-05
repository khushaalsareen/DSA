class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        for(auto it:arr){
            m[it]++;
        }
        int cnt = 0;
        for(int i = 0;i<arr.size();i++){
            if(m[arr[i]]==1){
                cnt++;
            }
            if(cnt == k)
            return arr[i];
        }
        return "";
    }
};