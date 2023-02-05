class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        
        stack<int> st;
        
        for (int i : nums) {
            while (i > 0) {
                st.push(i % 10);
                
                i /= 10;
            }
            
            while (!st.empty()) res.push_back(st.top()), st.pop();
        }
        
        return res;
    }
};