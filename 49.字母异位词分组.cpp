/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //设置一个map来记录相同字母不同排序的字符串
        unordered_map<string,vector<string>> M;
        //因为每个数值中记录的都是相同字母组成的字符串
        //所以将单词排序后的字符串做为键值
        for (string & s : strs) {
            //临时字符串，用来做为排序后的键值
            string temp = s;
            //排序
            sort (temp.begin() , temp.end());
            //将排序后的字符串做为键值，将原字符串保存在数组中
            M[temp].push_back(s);
        }
        //用来记录最终结果的二维数组
        vector<vector<string>> ans;
        //按键值进行遍历和将结果存入最终数组中
        for(auto it = M.begin(); it != M.end(); it++) 
            ans.push_back(it->second);
        return ans;
    }
};
// @lc code=end

