/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

    //利用快慢指针来查找链表的中间节点
    ListNode* MID(ListNode* head){
        //快指针比慢指针永远快一步
        ListNode* fast=head;
        ListNode* slow=head;
        //当快指针走到末尾时，慢指针则刚好走了一半
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        //返回慢指针
        return slow;

    }
    //对链表进行反转
    ListNode* REVERSE(ListNode* head){
        ListNode *pre; //记录前一个节点
        ListNode *cur; //记录当前节点
        ListNode *next; //记录下一个节点
        cur=head;
        pre=NULL;
        while(cur!=NULL)
        {
            next=cur->next; //保存cur的下一个节点
            cur->next=pre; //令当前节点指向前一个节点
            pre=cur; //更新pre的值
            cur=next; //当前节点向后移一位
        }
        return pre; //pre此时已经到最后一个节点，也就是反转后的头节点
    }


    void reorderList(ListNode* head) {
        if(!head) return;
        
        ListNode* mid=MID(head); //获取中间节点
        //cout<<mid->val;

        //通过中间节点，分为右链表和左链表
        ListNode* left=head; 
        ListNode* right=mid->next;
        mid->next=nullptr; //断开链表，分为左右链表

        //对右边链表进行反转
        right=REVERSE(right);
        //cout<<right->next->val;

        //将左链表和反转后的右链表合并
        ListNode* L_temp; //保存left当前节点的下一个节点
        ListNode* R_temp; //保存right当前节点的下一个节点
        
        //将两个链表进行合并
        while(left->next!=nullptr && right!=nullptr){

            L_temp=left->next;//保存下一个节点
            R_temp=right->next;//保存下一个节点
            
            //连个链表进行相连
            left->next=right; 
            right->next=L_temp;

            //更新left和right节点的位置
            left=L_temp;
            right=R_temp;
        }
    }
};
// @lc code=end

