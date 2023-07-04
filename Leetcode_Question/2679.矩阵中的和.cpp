class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;

        int row = nums.size();
        int col = nums[0].size();

        for (int i = 0; i < row; i ++) sort(nums[i].begin(), nums[i].end());

        for (int i = 0; i < col; i ++) {
            int idx = 0;
            for (int j = 0; j < row; j ++) {
                idx = max(idx, nums[j][i]);
            }

            res += idx;
        }

        return res;
        // // 按列排序
        // sort(nums.begin(), nums.end(), [](const vector<int> &a, const vector<int> &b) {return a[1] > b[1];});

        // for (int i = 0; i < nums.size(); i ++) {
        //     for (int j = 0; j < nums[i].size(); j ++) cout << nums[i][j] << " ";

        //     cout << endl;
        // }

        // cout << "------------------------------------" << endl;

        // int res = 0;

        // for (int i = 0; i < nums[0].size(); i ++) {
        //     cout << nums[0][i] << " ";
        //     res += nums[0][i];
        // }

        // cout << endl;

        // return res;
    }
};