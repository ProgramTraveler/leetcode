/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //获取digits数组的长度
        int num=digits.size()-1;
        //标志位为1，因为要求我们给末尾数字加1，那么就相当于后面有数字进1
        int flag=1;
        while(num>=0){
            //int temp=digits[num]/10;
            //如果当前数字加上标志位比10大，说明要进位
            if(digits[num]+flag>=10){
                //temp记录相加后的数字
                int temp=digits[num]+flag;
                //更新标志位
                flag=temp/10;
                //将进位后的数字记录在原数组处
                digits[num]=temp%10;
            }else{
                //如果加上标志位比10小的话，更新当前数组的数字
                digits[num]=digits[num]+flag;
                //cout<<flag<<endl;
                //返回最后结果
                return digits;
            }
            num--;
        }
        //如果在循环没有中途结束说明数组一直在加例如[9,9]这种情况
        //定义一个新的数组，比原数组长一位
        vector<int> ans(digits.size()+1);
        //cout<<ans.size()<<endl;
        //给第一位赋值为标志位
        ans[0]=flag;
        //for(int i=0;i<digits.size();i++) ans.push_back(digits[i]);
        return ans;        


    }
};
// @lc code=end

