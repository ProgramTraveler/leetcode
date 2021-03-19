/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        ParkSum[1] = big;
        ParkSum[2] = medium;
        ParkSum[3] = small;
    }
    
    bool addCar(int carType) {
        if (ParkSum[carType]) {
            ParkSum[carType] --;
            return true;
        }else 
            return false;
    }
private:
    unordered_map<int, int> ParkSum;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

