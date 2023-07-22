/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 记录收到的 5 美元 和 10 美元的个数
        // 20 不用记录 因为不会作为 零钱找出
        unordered_map<int, int> cnt;
        

        for (auto b : bills) {
            cnt[b] ++; // 当前零钱次数加 一

            if (b == 10) {
                if (cnt[5] >= 1) cnt[5] --;

                else return false;
            }
           
            if (b == 20) {
                if (cnt[5] >= 1 && cnt[10] >= 1) cnt[5] --, cnt[10] --;

                else if (cnt[5] >=3) cnt[5] -= 3;

                else return false; 
            } 
        }

        return true;
    }
};

// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         //当前你手中的余额
//         //unordered_map<int,int>balance;
//         //记录手中的5块和10块的张数
//         int five=0;
//         int ten=0;
//         for(int i=0;i<bills.size();i++){
//             if(bills[i]==5) {
//                five++; 
//             }//balance[5]++;
//             if(bills[i]==10) {
//                 if(five>0)/*(balance[5]>0)*/{
//                     //balance[5]--;
//                     five--;
//                     //balance[10]++;
//                     ten++;
//                 }else return false;
//             }
//            if(bills[i]==20){
//                if(five>0 && ten>0)/*(balance[5]>0 && balance[10]>0)*/{
//                    //balance[5]--;
//                    //balance[10]--;
//                    //balance[20]++;
//                    five--;
//                    ten--;
//                }else if(five>=3)/*(balance[5]>=3)*/{
//                    //balance[5]-=3;
//                    //balance[20]++;
//                    five-=3;
//                }else return false;
//            }
//         }
//         return true;
//     }
// };

// @lc code=end

