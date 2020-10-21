/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int tem1=0; //name的指针
        int tem2=0; //typed的指针
        //对两个数组进行比较
        while(tem2<typed.size()){
            //如果两个字符相同，就同时向后移
            if(typed[tem2]==name[tem1]){
                tem1++;
                tem2++;
            }else if(tem2>0 && typed[tem2]==typed[tem2-1]) tem2++; //如果name和typed不相同，看typed是否和之前一样，如果一样就移动它
            //否则就返回false
            else return false;
        }
        //最后判断name里的字符是否判断完了
        return tem1==name.size();
    }
};
// @lc code=end

