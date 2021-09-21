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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false; //就一个数据没有环
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (slow != NULL && fast != NULL && fast -> next != NULL) { //对fast的是否为空的判断要放在fast -> next 的判断之前
            if (fast == slow) return true;
            else {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
        }
        return false;

    }
};
// @lc code=end

