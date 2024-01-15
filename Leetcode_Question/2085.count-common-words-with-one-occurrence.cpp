/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 * @lcpr version=30113
 *
 * [2085] 统计出现过一次的公共字符串
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
    int countWords(vector<string>& words1, vector<string>& words2) {
        int res = 0;

        std::unordered_map<string, int> al1;
        std::unordered_map<string, int> al2;

        for (const auto& s : words1) al1[s] ++, al2[s] ++;
        for (const auto& s : words2) al2[s] ++;

        for (const auto& [k, v] : al2) {
          if (v == 2 && al1[k] == 1) res ++;
        }


        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["leetcode","is","amazing","as","is"]\n["amazing","leetcode","is"]\n
// @lcpr case=end

// @lcpr case=start
// ["b","bb","bbb"]\n["a","aa","aaa"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab"]\n["a","a","a","ab"]\n
// @lcpr case=end

 */

