class Solution {
public:
    int captureForts(vector<int>& forts) {
        // 从自己控制的城堡出发 到空地停止
        // 如果有两个 空地 应该选择哪个空地？
        int res = 0;

        int n = forts.size();

        for (int i = 0; i < forts.size(); i ++) {
            if (forts[i] == 1) {
                for (int j = i + 1; j < forts.size(); j ++) {
                    if (forts[j] == 1) break;

                    if (forts[j] == -1) {
                        res = max(res, abs(i - j) - 1);

                        break;
                    }
                }
            }

        }

        for (int i = n - 1; i >= 0; i --) {
            if (forts[i] == 1) {
                for (int j = i - 1; j >= 0; j --) {
                    if (forts[j] == 1) break;

                    if (forts[j] == -1) {
                        res = max(res, abs(i - j) - 1);

                        break;
                    }

                }
            }
        }

        return res;

    }
};