/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st; // 使用单调栈来记录。
        vector<bool> visit(26, false); // 记录每个字符是否已在栈中
        vector<int> charCount(26, 0); // 记录每个字符剩余的次数
        //思路：维护一个单调递增栈，在每次出栈时增加一个原则：如果栈顶元素在后面已经没有了，就不能再出栈。
        //入栈的原则：如果栈中已有该元素，则不入栈；否则入栈；

        for (auto &a : s) {
            charCount[a - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            charCount[s[i] - 'a']--; // 注意更新元素的剩余次数

            if (st.empty()) {
                st.push(s[i]);
                visit[s[i] - 'a'] = true; // 注意更新访问记录，第一次没过就是这里没更新
                continue;
            }

            // 几个条件说明：!st.empty() && s[i] < st.top() -- 单调递增栈要求
            // !visit[s[i] - 'a'] -- 如果当前元素已经在栈里了，肯定不用再入栈
            // charCount[st.top() - 'a'] > 0 -- 如果栈顶元素，在剩余的数组里已经不再出现了，那就不能出栈（因为要求每个数字至少出现一次）
            while (!st.empty() && s[i] < st.top() && !visit[s[i] - 'a'] && charCount[st.top() - 'a'] > 0) {
                visit[st.top() - 'a'] = false; // 注意更新栈中的元素访问记录
                st.pop();
            }

            if (!visit[s[i] - 'a']) {
                st.push(s[i]);
                visit[s[i] - 'a'] = true; // 注意更新栈中的元素访问记录
            }
        }

        string answer;
        while (!st.empty()) {
            answer += st.top();
            st.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;

    }
};


// @lc code=end

