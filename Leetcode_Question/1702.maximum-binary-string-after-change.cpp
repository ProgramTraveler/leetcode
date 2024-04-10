/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 * @lcpr version=30121
 *
 * [1702] 修改后的最大二进制字符串
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
    string maximumBinaryString(string binary) {
        int i = binary.find('0');
        if (i < 0) { // binary 全是 '1'
            return binary;
        }
        int cnt1 = count(binary.begin() + i, binary.end(), '1'); // 统计 [i, n-1] 中 '1' 的个数
        return string(binary.size() - 1 - cnt1, '1') + '0' + string(cnt1, '1');
    }
};
// @lc code=end



/*
// @lcpr case=start
// "000110"\n
// @lcpr case=end

// @lcpr case=start
// "01"\n
// @lcpr case=end

 */

