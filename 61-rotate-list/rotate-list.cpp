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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(!head || !head->next) return head;
        ListNode* h = head;
        int n = 0;
        while(h)
        {
            n++;
            h = h->next;
        }
        k = k % n;
        for(int i = 0; i < k; i++)
        {
            ListNode* temp = head;
            while(temp->next->next) temp = temp->next;

            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }

        return head;
    }
};