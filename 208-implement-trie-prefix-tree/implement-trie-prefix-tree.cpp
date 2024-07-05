struct Node{
    Node* arr[26];
    bool flag;
    Node(){
        flag = false;
        for(int i = 0;i<26;i++){
            arr[i] = NULL;
        }
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node  =root;
        for(int i = 0;i<word.size();i++){
            if(node->arr[word[i]-'a']==NULL){
                node->arr[word[i]-'a'] = new Node();
            }
            node = node->arr[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node*node = root;
        for(int i = 0;i<word.size();i++){
            if(node->arr[word[i]-'a']==NULL)
            return false;
            else
            node = node->arr[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->arr[prefix[i]-'a']==NULL)
            return false;
            else
            node = node->arr[prefix[i]-'a'];
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