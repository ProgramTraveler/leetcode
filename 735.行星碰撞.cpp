/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> result;
        stack<int> res;
        for(int i=0;i<asteroids.size();i++)
        {
            int flag=1;
            //当左边的元素为正数，右边的元素为负数的时候才会发生碰撞
            while(!res.empty()&&res.top()*asteroids[i]<=0&&asteroids[i]<0)
            {
                //当左边的正数<右边的负数时候
                if(res.top()+asteroids[i]<0)
                {
                    res.pop();
                    flag=1;//负数要进栈的，给个标志位
                }
                else if(res.top()+asteroids[i]>0)
                {
                    flag=0;//给个标志位，负数被碰撞消失了，标志着负数不能进栈
                    break;//左边的正数绝对值大于来的负数，消灭掉负数，跳出break
                }
                else if(res.top()+asteroids[i]==0)
                //正数和负数之和为0的时候
                {
                    flag=0;//新来的负数也不能进栈
                    res.pop();//里面的和外来的同归于尽
                    break;
                }
            }

            if(flag==0) continue;//flag为0的时候对应上面2种情况，不进行新元素的push
            else if(res.empty()||flag==1) res.push(asteroids[i]);
        }
        //此时，栈res中剩下的就是最后存活下来的元素（星球）
        //栈底为最左边的元素，栈顶是最右边的元素
        //为了恢复从左到右的排序，再来一个栈
        stack<int> temp;
        while(!res.empty())
        {
            temp.push(res.top());
            res.pop();
        }
        while(!temp.empty())
        {
            result.push_back(temp.top());
            temp.pop();
        }
        return result; 
    }
};
// @lc code=end

