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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> mapping;

        while(head)
        {
            if(mapping.find(head) != mapping.end()) return head;

            mapping.insert(head);

            head = head->next;
        }

        return NULL;
    }
};