/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};

// class Solution {
// public:
//     vector<int> prevPermOpt1(vector<int>& arr) {
//         // 交换一次 -> 比原数组小的最大的

//         // 从最小位开始向前 尽量保证交换的是低位
//         int n = arr.size();

//         int l = 0, r = n - 1;

//         unordered_map<int, int> al;

//         int idx_j = INT_MIN;
//         int idx_i = INT_MIN;

//         bool flag = false;

//         vector<int> tem;

//         for (int i = 0; i < n; i ++) tem.push_back(arr[i]);

//         for (int i = n - 1; i >= 0; i --) {

//             for (int j = i; j >= 0; j --) {

//                 if (arr[j] > arr[i]) {
//                     // flag = true;

//                     // swap(arr[i], arr[j]);

//                     al[i] = j;
                
//                     break;
//                 }
//             }

//             // if (flag) break;

//         }

//         flag = false;

//         for (int i = 0; i < n; i ++) {
//             for (int j = i; j < n; j ++) {
//                 if (tem[i] > tem[j]) {
//                     flag = true;

//                     swap(tem[i], tem[j]);

//                     break;
//                 }
//             }

//             if (flag) break;
//         }

//         // for (int i = 0; i < n; i ++) {
//         //     cout << arr[i] << " ";
//         // }

//         // cout << endl;

//         // for (int i = 0; i < n; i ++) {
//         //     cout << tem[i] << " ";
//         // }

//         for (auto [k, v] : al) {
//             if (idx_j < v) {

//                 idx_j = v, idx_i = k;

//             } else if (idx_j == v) {

//                 idx_i = max(idx_i, k);

//             }
//         }

//         // for (auto [k, v] : al) {
//         //     if (v == 0) {
//         //         idx_j = v, idx_i = min(idx_i, k);
//         //     }
//         // }

//         if (idx_j >= 0) swap(arr[idx_j], arr[idx_i]);

//         // for (int i = 0; i < n; i ++) {
//         //     if (arr[i] > tem[i]) return arr;

//         //     else if (arr[i] < tem[i]) return tem;
//         // }

//         return arr;
//     }
// };
// @lc code=end

