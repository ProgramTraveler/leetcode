/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> timMa;

        for (int i = 0; i < keyName.size(); i ++) {
            string tem = keyTime[i], na = keyName[i];

            int ho = (tem[0] - '0') * 10 + tem[1] - '0', mi = (tem[3] - '0') * 10 + tem[4] - '0';

            timMa[na].emplace_back(ho * 60 + mi);

        }

        vector<string> res;

        for (auto &[name, list] : timMa) {
            sort(list.begin(), list.end()); // 搞不懂这个题目是怎么安排的 还整个乱序 数组的时间和天数没有关系 ？

            for (int i = 2; i < list.size(); i ++) {
                int tim1 = list[i - 2], tim2 = list[i];

                int diff = tim2 - tim1;

                if (diff <= 60) {
                    res.push_back(name);

                    break;
                }
            }
        }

        sort(res.begin(), res.end());

        return res;


        //  官方题目解释误人啊
        
        /*vector<int> min;

        for (int i = 0; i < keyTime.size(); i ++) { // 先将时间转换为分钟显示
            string tem = keyTime[i];
            //cout << tem[0] << ' ' << tem[1] << ' ' << tem[2] << ' ' << tem[3] << ' ' << tem[4] << endl;

            int ho = (tem[0] - '0') * 10 + tem[1] - '0', mi = (tem[3] - '0') * 10 + tem[4] - '0';

            min.push_back(ho * 60 + mi);

            //cout << ho << ' ' << mi << endl;
        }

        // 如果后一个时间减去前一个时间是负数的话说明到下一天了

        unordered_map<string, int> name; // 每个人打了多少次卡
        unordered_map<string, int> time; // 每个人上一次打卡的时间
        unordered_map<string, int> sum_time; // 每个人打卡累计的时间

        for (int i = 0; i < keyName.size(); i ++) {
            if (name[keyName[i]] == 0) time[keyName[i]] = min[i], name[keyName[i]] ++; // 还没打过卡 记录打卡的时间
        }

        for (auto& [k, v] : name) v = 0;

        for (int i = 0; i < keyName.size(); i ++) {
            int ti_nu = min[i] - time[keyName[i]]; // 打卡时间间隔

            //cout << min[i] << ' ' << time[keyName[i]] << endl;

            //cout << keyName[i] << ' ' << ti_nu << " " << (ti_nu + sum_time[keyName[i]]) << endl;

            if (ti_nu >= 0 && (ti_nu + sum_time[keyName[i]] <= 60)) { // 如果还没到下一天 而且间隔时间还没超过一小时
                name[keyName[i]] ++;  // 打卡次数加一

                time[keyName[i]] = min[i]; // 记录打卡时间

                sum_time[keyName[i]] += ti_nu; // 记录打卡累计时间

            } else if ((ti_nu < 0 && name[keyName[i]] < 3)) name[keyName[i]] = 1, time[keyName[i]] = min[i], sum_time[keyName[i]] = 0;
            else if ((ti_nu + sum_time[keyName[i]]) > 60 && name[keyName[i]] < 3) {
                name[keyName[i]] = 2; 
                sum_time[keyName[i]] = min[i] - time[keyName[i]];
                time[keyName[i]] = min[i];
            }
 
        }

        vector<string> res;

        for (auto& [k, v] : name) cout << k << " " << v << endl;

        for (auto& [k, v] : name) if (v >= 3) res.push_back(k);
        
        sort(res.begin(), res.end());

        return res;*/
    }
};
// @lc code=end

