class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(arr[i]*2)!=m.end())
            return true;
            if(((arr[i]&1 )== 0) && m.find(arr[i]/2)!=m.end())
            return true;
            m[arr[i]]++;
        }
        return false;
    }
};