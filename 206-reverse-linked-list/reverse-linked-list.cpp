/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Iterative Approach:
            // ListNode *newHead = NULL;
            // while(head != NULL)
            // {
            //     ListNode *next = head->next;
            //     head->next = newHead;
            //     newHead = head;
            //     head = next;
            // }
            // return newHead;

        //Recursive Approach:
            if(head == NULL || head->next == NULL)
                return head;
            
            ListNode *nnode = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;

            return nnode;
    }
};