class Solution {
public:
    bool isCircularSentence(string sentence) {
        // 遍历比较
        // 最后一个的单词的最后一个字符 和 第一个单词的第一个字符

        char fir, end;
        int n = sentence.size();

        if (sentence[0] != sentence[n - 1]) return false; // 优先比较

        for (int i = 0; i < n; i ++) {
            if (sentence[i] == ' ') { // 出现空格 比较空格两边
                if (sentence[i - 1] != sentence[i + 1]) return false;
            }
        }

        return true;
    }
};