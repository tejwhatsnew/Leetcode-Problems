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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;

        ListNode* dummy = head;
        int n = 0;

        while(dummy)
        {
            n++;
            ans.push_back(dummy->val);
            dummy = dummy->next;
        }

        for(int i = 0; i < n/2; i++)
        {
            if(ans[i] != ans[n-i-1]) return false;
        }

        return true;
    }
};