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
    int generateLength(ListNode* head)
    {
        int i = 0;
        while(head)
        {
            i++;
            head = head->next;
        }

        return i;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int i = generateLength(head);
        int s = i / k;
        int extra = i % k;
        ListNode* curr = head;
        ListNode* pre = NULL;

        while(head)
        {
            int j = s;
            ans.push_back(curr);
            while(j > 0)
            {
                pre = curr;
                curr = curr->next;
                j--;
            }
            if(extra != 0 && curr != NULL)
            {
                pre = curr;
                curr = curr->next;
                extra--;
            }
            if(pre != NULL)
            {
                head = curr;
                pre->next = NULL;
            }
        }
        while(ans.size() != k) ans.push_back(NULL);

        return ans;
    }
};