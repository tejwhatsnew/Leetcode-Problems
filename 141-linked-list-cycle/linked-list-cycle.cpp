/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>hash;
        // ListNode *temp = head;
        while(head)
        {
            hash.insert(head);
            if(hash.find(head->next) != hash.end()) return true;

            head = head->next;
        }

        return false;
    }
};