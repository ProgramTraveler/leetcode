/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    //删除倒数第n个节点，可以变为两个节点相距n的距离（设i与j相距n个节点，当j为空的时候，那么i就是要删除的前一个节点，这样就可以直接按常规的删除手段就行了）
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *answer=new ListNode(0); //定义一个哨兵节点

        if(!head) return head; //对特殊情况的讨论

        answer->next=head;//哨兵节点指向头节点 
        
        ListNode *cur=answer; //定义后面的指针（相当于j）
        ListNode *pre=answer;//定义前面的指针（相当于i）
        for(int i=0;i<n;i++)
        {
            cur=cur->next; //让cur到于pre相距的位置
        }
        //如果cur的下一个节点不为NULL，两个点同时向后移动
        while(cur->next)
        {
            pre=pre->next;
            cur=cur->next;
        }
        
        //常规的删除节点
        pre->next=pre->next->next;

        return answer->next;

    }
};
// @lc code=end

