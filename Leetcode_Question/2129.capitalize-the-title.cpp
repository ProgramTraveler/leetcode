/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 * @lcpr version=30117
 *
 * [2129] 将标题首字母大写
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
    string capitalizeTitle(string title) {
        // toupper & tolower
        // 不存在前导和后缀空格
        // l 记录首字母位置，r 记录空格前到位置
        int l = 0, r = 0; 
        std::string res;
        int n = title.size();
        while (l < n && r < n) {
            if (r == n - 1) { // 最后一个字母
                // res.push_back(title[r]);
                if (r - l + 1 >= 3) {
                    res[l] = std::toupper(title[l]);
                } else {
                    res[l] = std::tolower(title[l]);
                 }
            }
            if (title[r] == ' ') { // 空格
                res.push_back(title[r]);
                if (r - l >= 3) {
                    res[l] = std::toupper(title[l]);
                } else {
                    res[l] = std::tolower(title[l]);
                }
                r ++;
                l = r;
                continue;
            }
            res.push_back(tolower(title[r]));
            r ++;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "capiTalIze tHe titLe"\n
// @lcpr case=end

// @lcpr case=start
// "First leTTeR of EACH Word"\n
// @lcpr case=end

// @lcpr case=start
// "i lOve leetcode"\n
// @lcpr case=end

 */

