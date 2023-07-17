/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        int add = 0; // 进位
        int cnt1 = 0, cnt2 = 0;

        while (n1 >= 0 || n2 >= 0 || add != 0) {
            
            cnt1 = n1 >= 0 ? num1[n1] - '0' : 0;
            cnt2 = n2 >= 0 ? num2[n2] - '0' : 0;

            res.push_back('0' + (cnt1 + cnt2 + add) % 10);

            add = (cnt1 + cnt2 + add) / 10;

            n1 --, n2 --;
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};


// class Solution {
// public:
//     string addStrings(string num1, string num2)
//      {
//          //定义两个指针，记录num1和num2最后的下标
//         int i=num1.size()-1;
//         int j=num2.size()-1;
//         //初始化一个string类型的ans，保存计算结果
//         string ans="";
//         //记录进位
//         int add=0;
//         //记录每次两个string的值
//         int x,y;
//         //保存x和y的和
//         int Alladd=0;
//         while(i>=0 || j>=0 || add!=0)
//         {
//             //（b=a？1:0）如果a是真，就等于1，a是假就为0
//             x=i>=0 ?(num1[i]-'0'):0;
//             y=j>=0 ?(num2[j]-'0'):0;
//             Alladd=x+y;
//             //将结果放在ans的末尾
//             ans.push_back('0'+(Alladd+add)%10);
//             add=(Alladd+add)/10;
//             //更新指针
//             i--;
//             j--;

//         }
//         //翻转ans的值
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
// @lc code=end

