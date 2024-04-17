class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                idx = i;
                break;
            }
        }
        int i = 0;
        int j = idx;
        while(i<j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;
    }
};