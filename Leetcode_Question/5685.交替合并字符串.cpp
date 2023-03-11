/*
 * @lc app=leetcode.cn id=5685 lang=cpp
 *
 * [5685] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        for (int i = 0; i < word1.size() && i < word2.size(); i ++) {
            ans += word1[i];
            ans += word2[i];
        }
        int l1 = word1.size();
        int l2 = word2.size();
        cout<<ans<<endl;
        if (l1 > l2) {
            for (int i = l2; i < l1; i ++) {
                cout<<word1[i]<<endl;
                ans += word1[i];
            }
            
        }else if (l2 > l1){
            for (int i = l1; i < l2; i ++)
                ans += word2[i];
        }else {
        
        }
        return ans;
    }
};
// @lc code=end

