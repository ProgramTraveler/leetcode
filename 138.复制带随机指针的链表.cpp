/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head) return head;
        map<Node* ,Node*> MAP; //hash<原来的链表节点,对应位置新链表节点>
        Node* cur=head;
        //遍历原链表，建立与新链表的映射关系
        while(cur)
        {
            MAP[cur]=new Node(cur->val);
            cur=cur->next;
        }
        //遍历原链表，利用MAP将新链表连接起来（理解不了的话建议画图）
        cur=head;
        while(cur)
        {
            Node* node=MAP[cur];
            node->next=MAP[cur->next];
            node->random=MAP[cur->random];
            cur=cur->next;     
        }
        return MAP[head];  
    }
};
// @lc code=end

