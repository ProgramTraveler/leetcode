/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* due = new ListNode(-1);
        ListNode* p = head;
        ListNode* q = due;
        while (p != nullptr) {
            if (p -> val != val) {
                q -> next = p;
                q = q -> next;
            }
            p = p -> next;
        }
        q -> next = nullptr;
        return due -> next;
    }
};
// @lc code=end

