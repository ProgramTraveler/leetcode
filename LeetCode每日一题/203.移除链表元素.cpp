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
        ListNode* due = new ListNode(-1); //设置一个虚拟节点，用来处理当头节点为目标值时的情况
        ListNode* p = head; //指向头节点
        ListNode* q = due; //指向虚拟节点
        while (p != nullptr) {
            if (p -> val != val) { //当前节点的值不是目标值
                q -> next = p; //q指向当前节点
                q = q -> next; //q指针后移一位
            }
            p = p -> next; //当前节点是目标值的话，就跳过
        }
        q -> next = nullptr; //用来处理当目标值在最后的位置的情况
        return due -> next;
    }
};
// @lc code=end

