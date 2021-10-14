class Solution {
public:
    /*
        山峰不能是边界的两个下标，一定是数组内部的，考虑二分
        但其实山峰的顶就是最大值，暴力点就是直接扫出最大值
    */
    int peakIndexInMountainArray(vector<int>& arr) { 
        /*
        暴力
        int res = 0, index = INT_MIN;
        for (int i = 0; i < arr.size(); i ++) {
            if (index < arr[i]) {
                res = i;
                index = arr[i];
            } 
        }
        return res;*/

        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            cout<< mid <<endl;
            if (arr[mid - 1] < arr[mid]) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};