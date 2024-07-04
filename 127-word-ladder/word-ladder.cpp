class Solution {
    bool differ(string &s1, string &s2){
        int i = 0;
        int j = 0;
        int size1 = s1.size(), size2 = s2.size();
        int cnt = 0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j])
            cnt++;
            i++;
            j++;
        }
        if(cnt==0)
        return abs(size1-size2) == 1;
        return cnt==1;
    }
public:
    int bfs(string &beginWord, string &target, vector<string>&wordList,unordered_set<string>&s){
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        
        while(!q.empty()){
            pair<string,int>p = q.front();
            q.pop();
            string &currWord = p.first;
            int steps = p.second;
            if(currWord == target)
            return steps+1;
            for(int i=0;i<wordList.size();i++){
                if(s.find(wordList[i])==s.end()){
                    if(differ(currWord,wordList[i])){
                      cout<<wordList[i]<<" "<<steps+1<<endl;
                       q.push({wordList[i],steps+1});
                       s.insert(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s;
       return bfs(beginWord, endWord,wordList, s);
    }
};