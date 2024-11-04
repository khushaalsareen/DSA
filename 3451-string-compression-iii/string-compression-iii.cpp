class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int i = 0;
        while(i<word.size()){
            char ch = word[i];
            int cnt = 1;
            int j = i+1;
            while(j<word.size() && cnt<9 && word[j]==ch){
                j++;
                cnt++;
            }
            string temp = to_string(cnt);
            temp.push_back(ch);
            ans+=temp;
            i = j;
        }
        return ans;
    }
};