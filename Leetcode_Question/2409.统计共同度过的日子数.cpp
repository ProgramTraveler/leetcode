int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
    int calc_days(string s) {
        int day = (s[3] - '0') * 10 + s[4] - '0';
        int month = (s[0] - '0') * 10 + s[1] - '0';
        for (int i = 0; i < month - 1; ++i) // 除了最后一个月份，前面的月份直接累加
            day += DAYS[i];
        return day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int left = calc_days(max(arriveAlice, arriveBob)); // 直接比较字符串再计算
        int right = calc_days(min(leaveAlice, leaveBob));
        return max(right - left + 1, 0); // 答案不能为负数
    }
};