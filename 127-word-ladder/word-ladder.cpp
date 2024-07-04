class Solution {
    
public:
    int bfs(string &beginWord, string &target, vector<string>&wordList,unordered_set<string>&s){
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            pair<string,int>p = q.front();
            q.pop();
            string &currWord = p.first;
            int steps = p.second;
            if(currWord == target)
            return steps;
            
            for(int i=0;i<currWord.size();i++){
                char original = currWord[i];
                for(char ch='a';ch<='z';ch++){
                    currWord[i] = ch;
                    if(s.find(currWord)!=s.end()){
                        q.push({currWord,steps+1});
                        s.erase(currWord);
                    }
                }
                currWord[i] = original;
            }
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
       unordered_set<string>s(wordList.begin(),wordList.end());
       return bfs(beginWord, endWord,wordList, s);
    }
};