/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *rev(ListNode *head ,ListNode *end)
    {
        ListNode *pre=NULL;
        ListNode *cur=head;
        while(cur!=end)
        {
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL )
        {
            return head;
        }
        ListNode *pre=head;
        ListNode *cur=head;
        //int count=0;
        for(int i=0;i<k;i++)
        {
            if(cur==NULL) return head;
            else cur=cur->next;
        }

        ListNode *Node=rev(pre,cur);
        pre->next=reverseKGroup(cur,k);
        return Node;

    }
};
// @lc code=end

