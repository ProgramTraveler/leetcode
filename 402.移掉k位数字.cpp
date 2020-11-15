/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
   string removeKdigits(string num, int k) {
	    stack<char> s;
	    for (int i = 0; i < num.size(); i++){
		    while (!s.empty() && s.top() > num[i] && k){
			    s.pop();
			    k--;
		    }
		    if (s.empty() && num[i] == '0')
			    continue;//跳过前置0
		    s.push(num[i]);
	    }
	    string result;
	    while (!s.empty()){
		    if (k > 0)//当还要再移除数字的时候：从此时单调递增栈的top部删去数字
			    k--;
		    else if (k == 0)//当不用再移除数字的时候：把字符串取出来到result
			    result += s.top();

		    s.pop();	
	    }
	    reverse(result.begin(), result.end());//stl中的reverse函数
	    return result == "" ? "0" : result;
    }
};
// @lc code=end

