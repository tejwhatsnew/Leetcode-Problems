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
        Node* iter = head, *front = head;
        
        while(iter != NULL)
        {
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        iter = head;

        while(iter != NULL)
        {
            iter->next->random = iter->random != NULL ? iter->random->next : NULL;
            iter = iter->next->next;
        }

        iter = head;
        Node* res = new Node(0);
        Node* temp = res;

        while(iter != NULL)
        {
            front = iter->next->next;
            temp->next = iter->next;
            iter->next = front;
            temp = temp->next;
            iter = iter->next;
        }

        return res->next;
    }
};