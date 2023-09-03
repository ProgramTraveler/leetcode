/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // 每分钟可以消灭一只怪物
        // 保底可以消灭一只
        // 每次消灭下一次离城市最近的
        // 第 0 分钟的时候怪物并没有动

        // int res = 0;

        // int min = 0; // 第 几分钟

        // while (1) {
        //     int idx = 0;
        //     int di = INT_MAX;
        //     bool fla = false;

        //     if (dist.size() == 0) break; // 如果全部消灭退出

        //     for (int i = 0; i < dist.size(); i ++) {
        //         if (dist[i] - speed[i] * min <= 0) { // 怪物已经进入城市 结束

        //             cout << "------------" << endl;
        //             cout << dist[i] << " " << speed[i] << " " << min << " " << dist[i] - speed[i] * min << endl;
        //             cout << "------------" << endl;
                    
        //             fla = true;

        //             idx = i;

        //             break;
        //         }

        //         if (di > (dist[i] - speed[i] * min)) idx = i, di = dist[i] - speed[i] * min; // 标记下一次距离城市最近的怪物

        //         // dist[i] = max(dist[i] - speed[i] * min, 0); // 更新怪物距离城市距离
        //     }

        //     cout << dist[idx] << " " << speed[idx] << " " << min << " " << fla << endl;

        //     if (fla) break;


        //     // 移除消灭的怪物
        //     dist.erase(dist.begin() + idx);
        //     speed.erase(speed.begin() + idx);

        //     // for (int i = 0; i < dist.size(); i ++) 
        //     res ++; // 消灭的怪物加一
        //     min ++; // 时间加一
        // }

        // return res;

        int n = dist.size();
        vector<int> arrivalTimes(n);
        for (int i = 0; i < n; i++) {
            arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1;
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= i) {
                return i;
            }
        }
        return n;
        
    }
};
// @lc code=end

