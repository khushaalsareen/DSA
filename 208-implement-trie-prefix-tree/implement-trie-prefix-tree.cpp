class Node{
public:
    Node*links[26];
    bool flag = false;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
    }
};

class Trie {
    Node*root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->links[word[i]-'a']==NULL){
                temp->links[word[i]-'a'] = new Node();
                temp = temp->links[word[i]-'a'];
            }
            else{
                temp = temp->links[word[i]-'a'];
            }
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node*temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->links[word[i]-'a']==NULL)
            return false;
            else
            temp = temp->links[word[i]-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node*temp = root;
        for(int i=0;i<prefix.size();i++){
            if(temp->links[prefix[i]-'a']==NULL)
            return false;
            else
            temp = temp->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */