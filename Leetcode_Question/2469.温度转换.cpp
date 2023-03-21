class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        // 建议和两数之和互换位置
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};