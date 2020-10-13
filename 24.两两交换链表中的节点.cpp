/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr; //如果链表为空，就直接返回空值

        ListNode* tempNode=new ListNode(0); //定义一个临时节点，方便返回
        tempNode->next=head; //指向头节点
        ListNode*prev=tempNode; 

        ListNode* first=head;
        

        while(first!=nullptr && first->next!=nullptr){
            ListNode* last=first->next;
            //相邻节点交换
            first->next=last->next;
            last->next=first;
            prev->next=last;
            //更新节点位置
            prev=first;
            first=first->next;
        }

        return tempNode->next;
        
        
    }
};
// @lc code=end

