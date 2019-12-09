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
    ListNode* l3 = new ListNode(0);
    ListNode* head = l3;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                l3->val += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                l3->val += l2->val;
                l2 = l2->next;
            }

            if(l3->val / 10)
            {
                l3->next = new ListNode(0);
                l3->next->val += l3->val/10;
                l3->val %= 10;
            }

            if((l1 != NULL || l2 != NULL) && l3->next == NULL)
            {
                l3->next = new ListNode(0);
                l3 = l3->next;
            }
            else if(l1 != NULL || l2 != NULL)
            {
                l3 = l3->next;
            }

            addTwoNumbers(l1, l2);
        }

        return head;
    }
};
