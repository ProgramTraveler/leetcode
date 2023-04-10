/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> ans;
    stack<int> st; // 单调栈（节点值）

    void f(ListNode *node, int i) {
        if (node == nullptr) {
            ans.resize(i); // i 就是链表长度
            return;
        }
        f(node -> next, i + 1);
        while (!st.empty() && st.top() <= node -> val)
            st.pop(); // 弹出无用数据
        if (!st.empty())
            ans[i] = st.top(); // 栈顶就是第 i 个节点的下一个更大元素
        st.push(node -> val);
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        f(head, 0);
        return ans;
        /*vector<int> res;

        vector<long long> L;
        ListNode* p = head;
        
        while (head) {
            L.push_back(head -> val);

            head = head -> next;
        }

        unordered_map<long long, long long> al;

        for (int i = 0; i < L.size(); i ++) al[L[i]] = i; // 有重复元素

        sort(L.begin(), L.end());
        
        stack<long long> st;

        for (int i = 0; i < L.size(); i ++) st.push(L[i]);

        while (p && !st.empty()) {
            
            if (al[p -> val] <= al[st.top()]) {

                if (p -> val < st.top()) res.push_back(st.top());

                else res.push_back(0);


                p = p -> next;

            } else {
                st.pop();
            }

        }

        return res;*/
    }

};
// @lc code=end

