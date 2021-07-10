/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
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
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
// @lc code=end

