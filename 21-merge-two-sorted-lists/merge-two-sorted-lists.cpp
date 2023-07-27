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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *list3 = NULL;
        ListNode* dummy = NULL;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                if(!list3)
                {
                    list3 = list1;
                    dummy = list3; 
                }
                else
                {
                    dummy->next = list1;
                    dummy = dummy->next;
                }
                list1 = list1->next;
            }
            else
            {
                if(!list3)
                {
                    list3 = list2;
                    dummy = list3; 
                }
                else
                {
                    dummy->next = list2;
                    dummy = dummy->next;
                }
                list2 = list2->next;
            }
        }
        if(list1)
        {
            dummy->next = list1;
           
        }
        else
        {
            dummy->next = list2;
        }
        return list3;
    }
};