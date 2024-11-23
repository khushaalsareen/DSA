class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& box){
        int m = box.size();
        int n = box[0].size();
        //m*n matrix
        //n*m matrix
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][i] = box[i][j];
            }
        }

        int i = 0;
        int j = ans[0].size()-1;
        while(i<j){
            for(int r=0;r<ans.size();r++){
                swap(ans[r][i],ans[r][j]);
            }
            i++;
            j--;
        }
        return ans;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>>ans = rotate(box);
        int m = ans.size();
        int n = ans[0].size();
        int j = n-1;
        while(j>=0){
            //for each column
            vector<int>NGE(m,m);
            stack<int>s;
            s.push(0);
            for(int i=1;i<m;i++){
                // index i is next obstacle of how many
                while(!s.empty() && ans[i][j]=='*'){
                    NGE[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
            unordered_map<int,int>mp;
            int lastSafe;
            for(int i=m-1;i>=0;i--){
                if(ans[i][j]=='#') // a stone
                {
                    int nextObs = NGE[i];
                    if(mp.find(nextObs)!=mp.end()){
                        lastSafe--;
                        swap(ans[i][j],ans[lastSafe][j]);
                    }
                    else{
                        lastSafe = NGE[i]-1;
                        mp[nextObs]++;
                        swap(ans[i][j],ans[lastSafe][j]);
                        
                    }
                }
            }
                j--;
        }
        return ans;
    }
};