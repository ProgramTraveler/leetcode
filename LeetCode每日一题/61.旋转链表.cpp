/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode *last=new ListNode(0);
        last=head;
        int len=1;
        if(!head) return head;
        while(last->next!=NULL) //最开始在判断里写的是（last！=NULL）。后来发现这样写最后的last是个NULL。这样就不能在后面写last->next=head了，老是在这里报错
        {
            len++; //记录链表的长度
            last=last->next; //将last指针指到最后一个节点
        }
        last->next=head; //将链表首尾相连，变成一个环
        //cout<<len;
        for(int i=0;i<(len-k%len);i++) last=last->next; //找到旋转后的那个新链表的尾节点
        ListNode *ans=last->next; //这个尾节点的前一个节点就是新的头结点 
        last->next=NULL; //将环断开，重新变成一个链表
        return ans;

    }
};
// @lc code=end

