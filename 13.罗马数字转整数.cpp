/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> Map;
        Map['I']=1;
        Map['V']=5;
        Map['X']=10;
        Map['L']=50;
        Map['C']=100;
        Map['D']=500;
        Map['M']=1000;
        int sum=0;
        for( int i = 0 ; i < s.length() ; ++ i ){
            if( i + 1 < s.length() && Map[s[i]] < Map[s[i+1]] )
                sum -= Map[s[i]];
            else 
               sum += Map[s[i]];
        }
        return sum;
        
    }
};
// @lc code=end

