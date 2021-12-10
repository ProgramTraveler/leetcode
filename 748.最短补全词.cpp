/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //array<int, 26> alp{};
        int alp[26] = {0}; //一定要对定义的数组进行初始化，初始化，初始化，重要的事情说三遍
        //string mold;
        //记录字符串中出现的字母数
        for (int i = 0; i < licensePlate.size(); i ++) {

            if (isalpha(licensePlate[i])) { //如果当前是一个字符 
                //记录其小写状态的个数
                alp[tolower(licensePlate[i]) - 'a'] ++;
            }
        }
        string res; //保存最后的结果 
        for (int i = 0; i < words.size(); i ++) {
            //array<int, 26> apltemp{};
            int apltemp[26] = {0};
            for (auto ch : words[i]) apltemp[ch - 'a'] ++;

            bool index = true;
            for (int j = 0; j < 26; j ++) {
                if (apltemp[j] < alp[j]) {
                    //cout << alp[j] << "---" << apltemp[j] <<endl;
                    index = false;
                    break;
                }
            }
            cout << index << endl;

            if (index && (res.size() == 0 || res.size() > words[i].size())) res = words[i];
        }
        return res;
    }
};
// @lc code=end

