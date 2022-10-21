/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX); // 单调栈的二元组分别表示股票出现的天数和股票价格
        idx = -1; // 当前天数
    }
    
    int next(int price) {
        idx ++; // 天数加一

        while (price >= st.top().second) st.pop();

        int res = idx - st.top().first;
        st.emplace(idx, price);

        return res;
    }

private:
    stack<pair<int, int>> st;
    int idx;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

