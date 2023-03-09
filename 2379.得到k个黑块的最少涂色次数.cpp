class Solution {
public:
    int minimumRecolors(string blocks, int k) { // 滑动窗口
        int res = INT_MAX, tem = 0;

        int l = 0, r = 0;

        while (r < blocks.size()) { // 能不能不要选大小写一样的字母

            if (r < blocks.size() && blocks[r] == 'W') tem ++;

            cout << "l: " << l << ' ' << "r: " << r << ' ' << tem << endl;

            if ((r - l + 1) == k) { // 达到窗口界限
                res = min(res, tem);

                if (blocks[l] == 'W') tem --;
                
                l ++, r ++;

            } else {
                // if (r < blocks.size() && blocks[r] == 'W') tem ++;

                r ++;
            }
        }

        return res;
    }
};