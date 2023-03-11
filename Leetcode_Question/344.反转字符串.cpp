/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    /*void reverseString(vector<char>& s) 
    {
        stack<char> ans; //利用栈翻转
        //把元素存在栈里
        for(int i=0;i<s.size();i++){
            ans.push(s[i]);
        }
        s.clear();//将原数组清空
        //把栈中元素放进数组中
        while(!ans.empty()){
            s.push_back(ans.top());
            ans.pop();
        }

    }*/
     void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++;
            right --;
        }
        //return s;
    }
};
// @lc code=end

