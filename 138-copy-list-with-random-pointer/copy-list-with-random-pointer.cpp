/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 7->5->4->2->1

        Node * t1 = head;
        Node *t2;
        while(t1){
            t2 = new Node(t1->val);
            Node * next = t1->next;
            t1->next = t2;
            t2->next = next;
            t1 = t1->next->next;
        }
        // 7->7->5->5->4->4
        Node * headNew = head?head->next:NULL;
        t1 = head;
        t2 = headNew;
        // set the random pointers
        while(t1){
            t1->next->random = t1->random? t1->random->next : NULL;
            t1 = t1->next->next;
        }
        t1 = head;
        //extract updated list
          t1 = head;
        // Node* headNew = head->next;
        t2 = headNew;

        while (t1 && t2) {
            t1->next = t2->next;
            t1 = t1->next;
            t2->next = t1 ? t1->next : NULL;
            t2 = t2->next;
        }

        // return headNew;
        return headNew;
    }
};