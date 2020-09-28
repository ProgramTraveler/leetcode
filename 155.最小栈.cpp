/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        ans.push_back(x); //把数存入数组
    }
    
    void pop() {
        ans.pop_back(); //把数取出数组
    }
    
    int top() {
        return ans.back(); //返回数组的最后一个元素
    }
    
    int getMin() {
        int Min=INT_MAX;
        for(int i=0;i<ans.size();i++)
        {
            Min=Min>ans[i] ?ans[i]:Min; //得出最小值
        }
        return Min;
    }
private:
    vector<int> ans;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

