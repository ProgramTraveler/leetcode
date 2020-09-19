/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head)
     {
         ListNode *pre;
         ListNode *cur;
         ListNode *next;
         cur=head;
         pre=NULL;
         while(cur!=NULL)
         {
             next=cur->next; //保存cur
             cur->next=pre; 
             pre=cur;
             cur=next;
         }
         return pre;
    }
};
// @lc code=end

