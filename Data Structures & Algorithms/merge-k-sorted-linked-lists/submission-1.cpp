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
    ListNode* mergeTwoLists(ListNode* lst1, ListNode* lst2) {
        if (!lst1 && !lst2) return nullptr;
        if (!lst1) return lst2;
        if (!lst2) return lst1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (lst1 && lst2) {
            if (lst1->val < lst2->val) {
                curr->next = lst1;
                lst1 = lst1->next;
            } else {
                curr->next = lst2;
                lst2 = lst2->next;
            }
            curr = curr->next;
        }

        if (lst1) {
            curr->next = lst1;
        }
        if (lst2) {
            curr->next = lst2;
        }
        return dummy->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* res = nullptr;

        for (ListNode* node: lists) {
            res = mergeTwoLists(res, node);
        }

        return res; 
    }
};
