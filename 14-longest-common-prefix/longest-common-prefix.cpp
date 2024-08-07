
struct Node{
    public:
    Node*links[26];
    bool flg = false;
    int cp = 0;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
    }
};

class Trie{
    Node*root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->links[word[i]-'a']==NULL){
                temp->links[word[i]-'a'] = new Node();
                temp = temp->links[word[i]-'a'];
                temp->cp++;
            }
            else{
                temp = temp->links[word[i]-'a'];
                 temp->cp++;
            }
        }
        temp->flg = true;
    }

    void search(string &word,string &ans, int total){
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            temp = temp->links[word[i]-'a'];
            if(temp->cp != total)
            break;
            else
            ans.push_back(word[i]);
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int idx = -1;
    int minSize = 1e9;
    int n  =arr.size();
    string ans = "";
    Trie trie;
    for(auto &it:arr){
        trie.insert(it);
    }
    trie.search(arr[0],ans, n);
    return ans;
    }
};