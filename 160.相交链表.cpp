/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr; //如果其中一个链表为空，直接返回空
        //定义两个初始节点，感觉和快慢指针有点像
        ListNode* head1 = headA;
        ListNode* head2 = headB;

        while (head1 != head2) { //循环开始条件，当两个节点不相同时
            if (head1 != nullptr) 
                head1 = head1 -> next;
            else head1 = headB;

            if (head2 != nullptr)
                head2 = head2 -> next;
            else head2 = headA;
        }
        return head1;
    }
};
// @lc code=end

