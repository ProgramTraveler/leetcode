/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    /*
    //简单的通过hash的方式来解决
    bool hasCycle(ListNode *head)
    {
        //return pos!=-1;
        map<ListNode * ,int> MAP;
        while (head!=NULL)
        {
            MAP[head]++; //对该节点进行计数
            if(MAP[head]>1) return true; //如果该点大于1，说明该点出现了两次（之前写的是MAP[head->val]，后来发现这个记录的数字，要说有重复的数字就错了）
            head=head->next;
        }
        return false;
    }
    */

    //hash很好理解，但这个题的标准解法还是用快慢指针
     bool hasCycle(ListNode *head)
     {
         if(head==NULL) return false;
         //保证快慢指针相差一个节点
         ListNode *fast=head->next; //设置一个快指针
         ListNode *slow=head; //设置一个慢指针（也可以拿head自己当慢指针。但为了方便理解是设置一个慢指针）
         while(slow!=NULL && fast!=NULL && fast->next!=NULL)
         {
             if(fast==slow) return true; //如果快指针追上了慢指针，说明这个是个环
             else
             {
                 fast=fast->next->next; //快指针每次跑两个节点
                 slow=slow->next; //慢指针一次一个节点
             }
         }
         return false;
     }

};
// @lc code=end

