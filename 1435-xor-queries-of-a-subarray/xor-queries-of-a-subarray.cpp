class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prefix(n,0);
        int psum = 0;
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]^arr[i];
        }
        vector<int>ans;
        int t = queries.size();
        for(int i=0;i<t;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
                ans.push_back(prefix[r]);
            }
            else{
                int ele = prefix[r] ^ prefix[l-1];
                ans.push_back(ele);
            }
        }
        return ans;
    }
};