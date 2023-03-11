/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
int manacher(string t){
    int res = 2;
    int Mx = 2;
    int index = 1;

    string s;
    s.push_back('$');
    for(auto x : t){
        s.push_back('#');
        s.push_back(x);
    }
    s.push_back('#');
    s.push_back('^');

    vector<int> dp(s.length(), 1);

    for(int i = 1; i < s.length()-1; i++){
        if(i < Mx){
            dp[i] = (dp[2*index - i] < (Mx - i) ? dp[2*index - i] : (Mx - i));
        }
        while(s[i-dp[i]] == s[i+dp[i]]) dp[i]++;
        if((i + dp[i]) > Mx){
            index = i;
            Mx = i + dp[i];
        }
        if((i - dp[i]) == 0) res = Mx-1;
    }
    
    return res/2;
}

    string shortestPalindrome(string s) 
    {
        int index = manacher(s);
        string t = s.substr(index);
        reverse(t.begin(), t.end());
        return t + s;
    }
};

// @lc code=end

