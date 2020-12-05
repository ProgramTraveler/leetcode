/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //获得这个任务的长度
         int len=tasks.size();
        //定义一个记录字母个数的数组
        vector<int> vec(26);
        //获得每个字母的个数
        for(char c:tasks) ++vec[c-'A'];
        //将数组中的元素按从大到小的顺序排列
        sort(vec.rbegin(),vec.rend());
        //sort(vec.begin(),vec.end(),[](int& x,int&y){return x>y;});
        //从第二大的列开始
        int cnt=1;
        //当前列和第一列的长度一样时，继续找下一列
        while(cnt<vec.size()&&vec[cnt]==vec[0]) cnt++;
        //返回最大的那个情况
        return max(len,cnt+(n+1)*(vec[0]-1) );
    }
};

// @lc code=end

