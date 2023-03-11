/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode(101, head); //注意链表中所给的值的范围，避开链表中的值的范围
        while (p -> next != nullptr) { //当该节点的下一个值不为空时，说明还没到最后的节点
            if (p -> val == p -> next -> val) { //如果当前的值和下一个节点的值相同
                p -> next = p -> next -> next; //去掉下一个节点
            }else {
                //否则当前节点向后移
                p = p -> next;
            }
        }
        //返回头节点
        return head;
    }
};
// @lc code=end

