/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] arr = s.toCharArray();
        int i = 0, j = arr.length - 1;
        while (i < j) {
            // 左指针指向元素非字母，指针右移
            if (!Character.isLetter(arr[i])) i ++; 
            // 右指针指向元素非字母，指针左移
            if (!Character.isLetter(arr[j])) j --; 
            // 左右指针指向元素皆为字母，交换元素后进行指针的左右移动
            if (Character.isLetter(arr[i]) && Character.isLetter(arr[j])) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i ++;
                j --; 
            }
        }
        return new String(arr);
    }
}
// @lc code=end

