/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* idx = new ListNode(0);

        res = idx;

        int cnt = 0, tem = 0;

        while (l1 != nullptr || l2 != nullptr) {
            ListNode* p = new ListNode(0);

            tem = (l1 == nullptr ? 0 : l1 -> val) + (l2 == nullptr ? 0 : l2 -> val) + cnt;

            // cout << tem << endl;

            cnt = tem / 10;

            p -> val =  tem % 10;

            idx -> next = p;
            idx = p;

            if (l1 != nullptr) l1 = l1 -> next; 
            if (l2 != nullptr) l2 = l2 -> next;
        }


        if (cnt != 0) {
            ListNode* p = new ListNode(0);
            p -> val = cnt;

            idx -> next = p;

            idx = p;
        }


        return res -> next;
    }
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//     {
//         ListNode *l3=new ListNode(0);
//         ListNode *p1=l1;
//         ListNode *p2=l2;
//         ListNode *p=l3;
//         int num=0;
//         int sum=0;
//         while(p1 || p2 ||num!=0)
//         {
//             sum=0;
//             if(p1)
//             {
//                 sum=sum+(p1->val);
//                 p1=p1->next;
//             }
//             if(p2)
//             {
//                 sum=sum+(p2->val);
//                 p2=p2->next;
//             }

//             sum=sum+num;
//             num=sum/10;
//             ListNode *t=new ListNode(sum%10);
//             p->next=t;
//             p=p->next;

            
//         }
//         return l3->next;
//     }
// };
// @lc code=end

