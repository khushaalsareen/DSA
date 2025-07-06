class Node{
public:
    int key;
    int val;
    Node*next;
    Node*prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int,Node*>m;
    Node*head;
    Node*tail;

    void deleteNode(Node*node){
        Node * prev = node->prev;
        Node * next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertAfterHead(Node * node){
        Node* next = head->next;
        head->next = node;
        node->next = next;
        node->prev = head;
        next->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        m.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        Node * node = m[key]; // found address of node
        deleteNode(node); // delete node from curr pos
        insertAfterHead(node); // this is latest used node so insrt afeetr head
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            // node with this value already exists so simpley update value
            Node * node = m[key];
            node->val = value;
            deleteNode(node); // delete at that postioin
            insertAfterHead(node); // insert after node this 
        }
        else{
        if(m.size()==capacity){
            Node * toDelete = tail->prev;
            deleteNode(toDelete); // delete this node
            int key_del = toDelete->key;
            m.erase(key_del);
            delete toDelete;
        }
        Node * newNode = new Node(key,value);
        insertAfterHead(newNode); // this is latest accessed node
        m[key] = newNode;
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */