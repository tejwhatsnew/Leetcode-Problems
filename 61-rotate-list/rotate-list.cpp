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
        if(!head || !head->next || k == 0) return head;
        ListNode* h = head;
        int n = 1;
        while(h->next)
        {
            ++n;
            h = h->next;
        }
        // n+=1;
        h->next = head;
        k = k % n;
        k = n - k;
        while(k--) h = h->next;

        head = h->next;
        h->next = NULL;
        
        return head;
    }
};