/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    void deleteNode(ListNode* node) {
        //其实就是把当前结点的值给改了，在把后面结点释放掉
        
        node -> val = node -> next -> val; //把当前删除的结点覆盖掉
        node -> next = node -> next -> next; //把后面结点给释放掉
    
    }
};
// @lc code=end

