/*
 * @lc app=leetcode.cn id=299 lang=cpp
 * @lcpr version=30117
 *
 * [299] 猜数字游戏
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        // 如果只有某个数字只有一个，且同时对应上公牛和母牛
        // 那么这个数字应该算公牛还是母牛？
        std::unordered_map<char, int> cnt;
        for (const auto& ch : secret) {
            cnt[ch] ++;
        }
        int n = secret.size();
        //* 优先查找公牛
        for (int i = 0; i < n; i ++) {
            if (secret[i] == guess[i]){
                x ++;
                cnt[secret[i]] --;
            }
        }
        //* 查找母牛
        for (int i = 0; i < n; i ++) {
            if (secret[i] != guess[i] && cnt[guess[i]] > 0) {
                y ++;
                cnt[guess[i]] --;
            }
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1807"\n"7810"\n
// @lcpr case=end

// @lcpr case=start
// "1123"\n"0111"\n
// @lcpr case=end

 */

