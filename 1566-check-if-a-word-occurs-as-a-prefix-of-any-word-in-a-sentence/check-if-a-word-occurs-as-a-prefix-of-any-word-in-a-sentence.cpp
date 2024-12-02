class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream s(sentence);
        string currentWord;
        int wordPos = 0;
        // while there are words to be processed in my sentence
        while(s>>currentWord){
            wordPos++;
            if(currentWord.length()>=searchWord.length() && 
            currentWord.compare(0,searchWord.size(),searchWord) == 0)
            return wordPos;
            
        }
        return -1;
    }
};