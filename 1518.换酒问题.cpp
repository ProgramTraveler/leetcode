/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int newBottle=0; //新换的瓶子数量
        int DrinkBo=numBottles; //喝剩下的瓶子数量
        int numDrink=numBottles; //喝过的瓶子数量
        //当喝剩下的瓶子数量不能再换了，结束循环
        while(DrinkBo>=numExchange){
            newBottle=DrinkBo/numExchange; //剩下的瓶子可以新换的瓶子数量
            numDrink+=newBottle; //新换的瓶子计入喝酒的瓶数
            DrinkBo=DrinkBo%numExchange; //再换酒后还剩的瓶子数量
            DrinkBo+=newBottle; //更新剩下的瓶子数量（换酒后剩下的加上新喝完的）
        }
        return numDrink;   
    }
};
// @lc code=end

