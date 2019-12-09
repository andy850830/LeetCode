class Solution {
public:
    int iCarry = 0;
    ListNode* l3 = new ListNode(0);
    ListNode* head = l3;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        while(l1 != NULL && l2 != NULL)
        {
            l3->val = l1->val + l2->val + iCarry;
            iCarry = 0;

            if(l3->val / 10)
            {
                iCarry = l3->val / 10;
                l3->val %= 10;
            }

            if(l1->next != NULL && l2->next != NULL)
            {
                l3->next = new ListNode(0);
                l3 = l3->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = (l1->val) + iCarry;
            iCarry = 0;

            if(l3->val / 10)
            {
                iCarry = l3->val / 10;
                l3->val %= 10;
            }

            l1 = l1->next;
        }

        while(l2 != NULL)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = (l2->val) + iCarry;
            iCarry = 0;

            if(l3->val / 10)
            {
                iCarry = l3->val / 10;
                l3->val %= 10;
            }

            l2 = l2->next;
        }

        if(iCarry != 0)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = iCarry;
        }

        return head;
    }
};
