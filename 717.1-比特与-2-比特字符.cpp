/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count=0;//记录数组里的下标位置
        //开始遍历数组
        while(count<bits.size()){
            //如果下标到达最后一个数，说明最后一个是前面匹配剩下的
            if(bits.size()-1==count){
                //获得数组最后一个数的下标
                int temp=bits.size()-1;
                //如果最后一个数是0的话，说明满足条件
                if(bits[temp]==0){
                    //返回true
                    return true;
                }else{
                    //如果最后一个数是1的话，不满足条件，返回false
                    return false;
                }
            }else{
                //如果没有到达最后一个位置的话，判断当前位置的数是1还是0
                if(bits[count]==0){
                    //是0的话就移动一位，因为它只需要一位字节
                    count++;
                }else{
                    //如果是1的话，就移动两位，因为它需要两位字节
                    count+=2;
                }
            }
        }
        return false;

    }
};
// @lc code=end

