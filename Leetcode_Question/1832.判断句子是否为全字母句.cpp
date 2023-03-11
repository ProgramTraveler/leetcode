/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        sort(sentence.begin(), sentence.end());

        sentence.erase(unique(sentence.begin(), sentence.end()), sentence.end()); // 去重

        return sentence.size() == 26;
    }
};
// @lc code=end

