/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
            
        //如果链表为空，直接返回空链表
        if(head==nullptr) return head;
        //一个新的节点，用来指向头
        ListNode* TempNode=new ListNode(0);
        //指向头节点
        TempNode->next=head;
        //定义一个节点在头节点，一个在头节点之后
        ListNode* LastNode=head;
        ListNode* cur=head->next;
        //开始对链表进行遍历
        while(cur!=nullptr){
            //如果当前的节点比后面的那个数小，就继续向后
            if(LastNode->val<=cur->val){
                LastNode=LastNode->next;
            }else{
                //否则的话就开始从头遍历，找到插入位置
                ListNode* temp=TempNode;
                while(temp->next->val<=cur->val){
                    //cout<<"A"<<endl;
                    temp=temp->next;
                }
                //维护前面的有序性
                LastNode->next=cur->next;
                cur->next=temp->next;
                temp->next=cur;
            }
            //cur向后移动
            cur=LastNode->next;
        }
        return TempNode->next;
    }

};
// @lc code=end

