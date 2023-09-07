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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* Lprev = dummy,* cur = head;
        for(int i = 0; i < left-1; i++)
        {
            Lprev = cur;
            cur = cur->next;
        }

        ListNode* prev = NULL;

        for(int i = 0; i < right - left + 1; i++)
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        Lprev->next->next = cur;
        Lprev->next = prev;

        return dummy->next;
    }
};