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
private:
    ListNode* reverseList(ListNode* node)
    {
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        while(node != NULL)
        {
            nex = node->next;
            node->next = pre;
            pre = node;
            node = nex;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;

        ListNode *fast = head, *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL)
            slow = slow->next;

        slow = reverseList(slow);

        while(slow != NULL)
        {
            if(head->val != slow->val) return false;

            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};