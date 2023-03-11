/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head; //定义快指针
        ListNode* slow=head; //定义慢指针
        //当快指针为空，或者快指针的next为空。说明慢指针已经到了中间节点（可以自己画图理解），返回slow即可
        while(fast!=NULL && fast->next!=NULL)
        {
            //快指针每次移动两位
            fast=fast->next;
            fast=fast->next;
            //慢指针移动一位
            slow=slow->next;
        }
        return slow;
    }
};
// @lc code=end

