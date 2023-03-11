/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(),g.end());//按胃口从小到大排序
        sort(s.begin(),s.end());//按尺寸从小到大排序

        int children=0;//能喂饱的孩子数量

        //之前写的能AC，但太慢了，优化为一个循环
        /*for(int i=0;i<g.size();i++){
            for(int j=0;j<s.size();j++){
                //如果当前孩子能被喂饱，数量加一，并把这个饼干拿出去
                if(s[j]>=g[i]){
                    children++;
                    s.erase(s.begin()+j);
                    break;
                }
                else continue;
            }
        }*/

        int cook=0; //饼干的下标
        //当孩子都被喂饱或者饼干被分配完。循环结束
        while(children<g.size() && cook<s.size()){
            //当这个饼干的尺寸大于等于孩子胃口
            if(g[children]<=s[cook]){
                //孩子数量加一
                children++;
            }
            //不管孩子能不能被喂饱，饼干都应该加一（因为如果孩子没被喂饱，应该去下一个饼干看能不能喂饱，如果这个孩子被喂饱了，那么这个饼干就不能再用了，还是要去下一个）
            cook++;
        }
        return children;

    }
};
// @lc code=end

