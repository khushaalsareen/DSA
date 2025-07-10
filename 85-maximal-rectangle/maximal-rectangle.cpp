class Solution {
    int largest(auto& v){
        stack<int>s;
        int n = v.size();
        s.push(0);
        int ans = 0;
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        for(int i = 1;i < n ; i++){
            while(!s.empty() && v[i]<v[s.top()]){
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
            
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && v[i]<v[s.top()]){
                pse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            int curr = v[i] * (nse[i]-pse[i]-1);
            ans = max(ans,curr);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> nums(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i][j] = matrix[i][j] - '0';
            }
        }
        int ans = 0;
        ans = max(ans, largest(nums[0]));
        for(int i=1;i<m;i++){
            vector<int>& v1 = nums[i];
            for(int j=0;j<nums[i].size();j++){
                if(nums[i][j]!=0){
                    nums[i][j] = 1 + nums[i-1][j];
                }
                    
            }
            ans = max(ans,largest(nums[i]));
        }
        return ans;
    }
};