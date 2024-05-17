/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 * @lcpr version=30122
 *
 * [2391] 收集垃圾的最少总时间
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int n = static_cast<int>(garbage.size());
        std::vector<int> f(n, 0);
        // 前缀和
        for (int i = 0; i < static_cast<int>(travel.size()); i ++) {
          f.at(i + 1) = f.at(i) + travel.at(i);
        }

        int cnt = 0, g_idx = 0;
        int p_idx = 0;
        int m_idx = 0;
        for (int i = 0; i < static_cast<int>(garbage.size()); i ++) {
          const string& gar = garbage.at(i);
          cnt += gar.size();
          if (gar.find("G") != std::string::npos) {
            g_idx = i;
          } 
          if (gar.find("P") != std::string::npos) {
            p_idx = i;
          }
          if (gar.find("M") != std::string::npos) {
            m_idx = i;
          }
        }

        std::cout << cnt << " " << f.at(g_idx) << " " << f.at(p_idx) << " " << f.at(m_idx) << endl;
        res = cnt + f.at(g_idx) + f.at(p_idx) + f.at(m_idx);

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["G","P","GP","GG"]\n[2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// ["MMM","PGM","GP"]\n[3,10]\n
// @lcpr case=end

 */

