/*
 * @lc app=leetcode.cn id=5601 lang=cpp
 *
 * [5601] 设计有序流
 */

// @lc code=start
class OrderedStream {
public:
    
    OrderedStream(int n) {
        //保存输入的id个数
        count=n;
    }
   
    vector<string> insert(int id, string value) {
        //清空临时数组（因为会保存之前记录的字符串）
        temp.clear();
        //cout<<"PTR:"<<ptr<<endl;
        //将ptrT数组中的下标位置给ptr
        ptr=ptrT[0];
        //将当前id的值传入字符串
        ans[id]=value;
        //如果当前指针位置是一个空值，而且没有超过当前的count
        if(ans[ptr]=="" && ptr<=count){
            //ptr=ptr;
            //直接返回空值（因为之前已经把temp数组中的值清空）
            return temp;
        }else{
            //如果当前的ptr的值不是一个空的，那么开始向后遍历，知道遇到空值
            while(ans[ptr]!="" && ptr<=count){
                //把当前的ptr指针的字符串的值存入temp数组中
                temp.push_back(ans[ptr]);
                //指针向后移
                ptr++;
            }
            //更新数组中的值，当前的ptr作为下一次的ptr的开始
            ptrT[0]=ptr;
            //返回当前的数组中的值
            return temp;    
        }
    }
    
private:
    //static int ptr;
    //记录ptr指针所在位置
    vector<int>ptrT={1};
    //初始化ptr指针
    int ptr=1;
    //初始化count的值
    int count=0;
    //记录当前ptr指针和之后的字符串
    vector<string> temp;
    //记录id和字符串的值
    map<int,string>ans;
};
//int OrderedStream::ptr=1;

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
// @lc code=end

