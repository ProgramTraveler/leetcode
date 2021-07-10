/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head){
        //定义快慢指针
        ListNode* fast=head;
        ListNode* slow=head;
        //判断是否有环
        while(fast!=nullptr && slow!=nullptr && fast->next!=nullptr){
            //慢指针每次走一步，快指针每次走两步
           slow=slow->next;
           fast=fast->next->next;
           //如果有环，找出环的入口
           if(slow==fast){
               while(head!=slow){
                   head=head->next;
                   slow=slow->next;
            }
            //返回环的入口节点
            return slow;
        }
    } 
    return nullptr;
        
    }
};
// @lc code=end

