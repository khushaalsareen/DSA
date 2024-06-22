class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxCnt = cnt;
        unordered_map<int,int>m;
        while(j<n){
            m[fruits[j]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0)
                m.erase(fruits[i]);
                i++;
            }
            maxCnt = max(maxCnt, j-i + 1);
            j++;
        }
        return maxCnt;
    }
};