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
        unordered_map<Node*, Node*> hash;
        Node* temp = head;
        while(temp)
        {
            Node* newNode = new Node(temp->val);
            hash[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        while(temp)
        {
            Node* node = hash[temp];
            node->next = (temp->next != NULL) ? hash[temp->next]:NULL;
            node->random = (temp->random != NULL) ? hash[temp->random]:NULL;
            temp = temp->next;
        }

        return hash[head];
    }
};