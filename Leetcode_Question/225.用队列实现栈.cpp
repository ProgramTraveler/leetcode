/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //队列入队
        ans.push(x);
        int num=ans.size()-1;
        //每次把队列中的最后元素送到队首
        for(int i=0;i<num;i++){
            ans.push(ans.front());
            ans.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //记录队列里的队首元素（因为把最后那个元素送到队首了，相当于栈顶）
        int temp=top();
        ans.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        //返回队首元素（也就是栈顶元素）
        return ans.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return ans.empty();
    }
private:
    queue<int> ans;
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

