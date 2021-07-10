/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> ans;//记录每个数字的出现次数
        //记录数字对应的出现的次数
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]++;
        }
        //使用迭代器记录每个数字出现的次数
        map<int,int>::iterator it = ans.begin();
        //记录出现的次数
        vector<int> res;
        //对res数组进行赋值
        while(it!=ans.end()){
            res.push_back(it->second);
            it++;
        }
        //对res数组进行排序方便比较
        sort(res.begin(),res.end());
        //开始遍历，检查是否有出现的相同的次数
        for(int i=0;i<res.size();i++){
            if(i>0 && res[i]==res[i-1]) return false;
            else continue;
        }

        return true;

    }
};
// @lc code=end

