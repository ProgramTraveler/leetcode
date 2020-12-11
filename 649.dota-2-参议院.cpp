/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
       //R和D为true表示Radiant和Dire都有存活
       bool R=true;
       bool D=true;
       //如果flag>0，规定为前面为Radiant，可以取消后面的Dire的权力
       //当flag<0时，则前面为Dire，可以取消后面的Radiant的权力
       int flag=0;
       //循环条件为Radiant和Dire都有存活
       while(R && D){
            //初始为R和D没有存活
            R=false;
            D=false;
            for(int i=0;i<senate.size();i++){
                if(senate[i]=='R'){
                    //如果当前为Ratiand，而且前面为Dire，那么它就会失去所以权力
                    if(flag<0) senate[i]=0;
                    //否则Radiant阵营有存活
                    else R=true;
                    //Randiant的人数加一
                    flag++;
                }
                if(senate[i]=='D'){
                    //如果当前的为Dire，而且前面是Radiant，那么它就会失去所有权力
                    if(flag>0) senate[i]=0;
                    //否则Dire阵营有存活
                    else D=true;
                    //Dire的人数加一
                    flag--;
                }
            }
       }
        //按阵营返回最后的赢家
        return R==true ? "Radiant" : "Dire";
    }
};


// @lc code=end

