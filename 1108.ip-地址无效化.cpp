/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        
        //for (auto& c : address)

        for (int i = 0; i < address.size(); i ++) {
            if (address[i] == '.') {
                res.append("[.]");
            } else {
                res.push_back(address[i]);
            }
        }

        return res;
    }
};
// @lc code=end

