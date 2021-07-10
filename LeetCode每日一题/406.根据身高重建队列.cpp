/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    //先排队再插队
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 身高从低到高排序
        sort(people.begin(), people.end());
        vector<vector<int>> res(people.size());
        // 遍历people
        for(auto & p : people){
            //cout<<p[0]<<endl;
            int count = -1; // 计算空位置或高度等于p[0]的位置
            for(int i = 0; i < res.size(); i++){
                // 位置上和我一样高或者如果一个位置是空的
                if(res[i].empty() || res[i][0] == p[0]) {
                    count++;
                }
                // 数到第k个位置
                if(count == p[1]){
                    res[i] = p;
                    break;
                }
            }
        }
        return res;
    }
};

// @lc code=end

