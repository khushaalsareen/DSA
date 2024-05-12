class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]] = i;
        }
        int sum = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            sum+= abs(i-m[ch]);
        }
        return sum;
    }
};