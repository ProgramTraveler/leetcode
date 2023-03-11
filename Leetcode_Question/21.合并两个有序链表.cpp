/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(-1); //新链表的头节点
        ListNode* pre = head; 
        //迭代停止条件
        while(l1 != nullptr && l2 != nullptr) {
            //如果l1的节点值比l2得我节点值大
            if(l1 -> val > l2 -> val) {
                //pre节点就指向l2，更新l2得节点
                pre -> next = l2;
                l2 = l2 -> next;
            }
            else {
                pre -> next = l1;
                l1 = l1 -> next;
            }

            pre = pre -> next;
        }
        //当循环停止后，l1或l2其中一个会是null
        pre -> next = l1 == nullptr ? l2 : l1;
        return head -> next;
        
    }
};
// @lc code=end

