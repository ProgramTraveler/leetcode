/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *l3=new ListNode(0);
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *p=l3;
        int num=0;
        int sum=0;
        while(p1 || p2 ||num!=0)
        {
            sum=0;
            if(p1)
            {
                sum=sum+(p1->val);
                p1=p1->next;
            }
            if(p2)
            {
                sum=sum+(p2->val);
                p2=p2->next;
            }

            sum=sum+num;
            num=sum/10;
            ListNode *t=new ListNode(sum%10);
            p->next=t;
            p=p->next;

            
        }
        return l3->next;
    }
};
// @lc code=end

