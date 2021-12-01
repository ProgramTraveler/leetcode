/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start

//不知道为什么第一次做的时候写的这么复杂化，可能是有点low

/*class Solution {
public:
    int maxPower(string s) {
        //设置一个数组存储26个数字，用来代表26个字母中连续重复的次数
        int ans[26] = {0};
        //设置两个指针，start指针来记录字母开始的位置，end指针来记录相同字母最后的位置
        int start = 0;
        int end = 0;
        //开始对字符串进行遍历
        while(start < s.size()) {
            //如果当前的字母和后一个字母相同，end继续向后移
            if(s[start] == s[end]) {
                end ++;
            }else {
                //如果end和start不相同，那么更新这段相同的字符串的长度
                int temp = s[start] - 'a';
                //更新字母的连续的字符串长度（要是以前就有值，还要和之前的比哪个长，保留长的在字符串）
                ans[temp] = max(ans[temp], (end - start));
                //更新start的位置，从和前一个字符串不相同的位置开始
                start = end;
            }
        }
        //定义一个Max来记录最长的字符串
        int Max = INT_MIN;
        //对ans数组进行遍历
        for(int i = 0; i < 26; i ++) {
            //cout<<ans[i]<<endl;
            //更新Max的值
            Max = max(ans[i], Max);
        }
        //返回最终结果
        return Max;
    }
};*/

//第二次几行就能解决

// @lc code=end

