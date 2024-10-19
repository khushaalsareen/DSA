class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = nullptr, Node* prev = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class LRUCache {
    int maxSize;
    int currSize;
    Node* head;
    Node* tail;
    unordered_map<int, pair<int, Node*>> m;

public:
    LRUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        Node* node = m[key].second;

        if (node != tail) {
            // Detach node from its current position
            if (node == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else {
                if (node->next) node->next->prev = node->prev;
                if (node->prev) node->prev->next = node->next;
            }

            // Move node to the tail
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = node;
        }

        return m[key].first;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Key already exists, update the value and move the node to the tail
            m[key].first = value;
            Node* node = m[key].second;

            if (node != tail) {
                // Detach node from its current position
                if (node == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                } else {
                    if (node->next) node->next->prev = node->prev;
                    if (node->prev) node->prev->next = node->next;
                }

                // Move node to the tail
                tail->next = node;
                node->prev = tail;
                node->next = nullptr;
                tail = node;
            }
        } else {
            // Insert new key
            Node* newNode = new Node(key);
            m[key] = {value, newNode};
            currSize++;

            if (tail == nullptr) {
                // First node in the cache
                head = newNode;
                tail = newNode;
            } else {
                // Add new node to the tail
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            // If cache exceeds capacity, remove least recently used (head)
            if (currSize > maxSize) {
                Node* toDelete = head;
                head = head->next;
                if (head) head->prev = nullptr;
                m.erase(toDelete->val);
                delete toDelete;
                currSize--;
            }
        }
    }
};
