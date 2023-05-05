class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        // 唯一 id
        int res = logs[0][0], time = logs[0][1];

        for (int i = 1; i < logs.size(); i ++) {
            int tem = logs[i][1] - logs[i - 1][1];

            if (tem == time) res = min(res, logs[i][0]);
            
            if (tem > time) res = logs[i][0], res, time = tem;
        }

        return res;
    }
};