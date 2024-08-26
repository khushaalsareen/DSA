class Node{
    public:
    Node* arr[26];
    int sw;
    bool eow;
    Node(){
        for(int i=0;i<26;i++)
        arr[i] = NULL;
        sw = 0;
        eow = false;
    } 
};
class Trie {
    Node *node;
public:
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        Node* temp = node;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(temp->arr[ch-'a']==NULL){
                temp->arr[ch-'a'] = new Node();
                temp = temp->arr[ch-'a'];
            }
            else
            temp = temp->arr[ch-'a'];
            temp->sw++;
        }
        temp->eow = true;
    }
    
    bool search(string word) {
        Node* temp = node;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']==NULL)
            return false;
            else
            temp = temp->arr[word[i]-'a'];
        }
        return temp->eow == true;
    }
    
    bool startsWith(string word) {
        Node*temp = node;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']==NULL)
            return false;
            else
            temp = temp->arr[word[i]-'a'];
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