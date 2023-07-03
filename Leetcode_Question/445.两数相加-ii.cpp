/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();

        ListNode* idx = res;

        stack<int> ll1, ll2;

        while (l1 != nullptr) ll1.push(l1 -> val), l1 = l1 -> next;

        while (l2 != nullptr) ll2.push(l2 -> val), l2 = l2 -> next;

        int cnt = 0; // 进位
        stack<int> ans;

        while (!ll1.empty() || !ll2.empty()) {
            int tem = (ll1.empty() ? 0 : ll1.top()) + (ll2.empty() ? 0 : ll2.top()) + cnt;

            ans.push(tem % 10);

            cnt = tem / 10;

            if (!ll1.empty()) ll1.pop();
            if (!ll2.empty()) ll2.pop();
        }

        if (cnt != 0) ans.push(cnt);

        while (!ans.empty()) {
            ListNode* p = new ListNode(ans.top());

            idx -> next = p;

            idx = p;

            ans.pop();
        }

        return res -> next; 
    }
};
// @lc code=end

