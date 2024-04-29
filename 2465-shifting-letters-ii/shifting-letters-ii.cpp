class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixSum(s.length()+1,0);
        for(auto x:shifts){
            if(x[2] == 0){
                prefixSum[x[0]]--;
                prefixSum[x[1]+1]++;
            }
            else{
                prefixSum[x[0]]++;
                prefixSum[x[1]+1]--;
            }
        }
        for(int i=1; i<s.length() ;i++){
            prefixSum[i] += prefixSum[i-1];
        }
        for(int i=0; i < s.length() ; i++){
           int n=((s[i]-'a')+prefixSum[i])%26;
            if(n<0) n+=26;
            s[i]=(char)(n+'a');
        }
        return s;
    }
};