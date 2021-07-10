/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int pos = 1;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && pos < m) {
            pre = pre->next;
            cur = cur->next;
            pos ++;
        }
        ListNode* tailNode = cur;
        while (cur && pos <= n) {
            ListNode* nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            tailNode->next = nxt;
            cur = nxt;
            pos ++;
        }
        return dummy->next;
    }
};
// @lc code=end

