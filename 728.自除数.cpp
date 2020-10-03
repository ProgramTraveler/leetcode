/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    //直接遍历求解
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> a;
        for(int i=left;i<=right;i++){
            int num = i;
            while(num>0){
                if(num%10 == 0||i%(num%10)!=0)
                    break;
                else
                    num/=10;
            }
            if(num == 0)
                a.push_back(i);
        }
        return a;
    }
};

// @lc code=end

