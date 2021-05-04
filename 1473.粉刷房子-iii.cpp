/*
 * @lc app=leetcode.cn id=1473 lang=cpp
 *
 * [1473] 粉刷房子 III
 */

// @lc code=start
const int INF = 0x3f3f3f3f;  //INF + INF 不会爆int
int f[105][25][105];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //无效的状态
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                f[i][j][0] = INF;
            }
        }

        for(int i = 1; i <= m; i++){
            int color = houses[i - 1];
            for(int j = 1; j <= n;j++){
                for(int k = 1; k <= target; k++){
                    if(k > i) {
                        f[i][j][k] = INF;
                        continue;
                    }
                    //第i个房间已经上色
                    if(color != 0){
                        if(j == color){
                            int cur = INF;
                            //与上一个房间颜色不同
                            for(int p = 1; p <= n; p++){
                                if(p != j){ //颜色不同
                                    cur = min(cur,f[i - 1][p][k - 1]);
                                }
                            }
                            //与上一个房间颜色相同
                            f[i][j][k] = min(cur,f[i - 1][j][k]);
                        }
                        else f[i][j][k] = INF; //其他为无效状态
                    }    
                    else{ //第i个房间未上色
                        int u = cost[i - 1][j - 1];
                        //考虑第i个房间是否形成新的分区
                        //与上一个房间颜色不同，形成新分区
                        int cur = INF;
                        for(int p = 1; p <= n; p++){
                            if(p != j) cur = min(cur,f[i - 1][p][k - 1] + u);
                        }
                        //与上一个房间颜色相同，不形成新的分区
                        f[i][j][k] = min(cur,f[i - 1][j][k] + u);
                    }   
                }
            }
        }
        
        int ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans,f[m][i][target]);
        }
        return ans == INF ? -1 : ans;
    }
};
// @lc code=end

