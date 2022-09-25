class Solution {
public:
    int lastMaterial(vector<int>& material) {
        sort(material.begin(), material.end());
        
        int n = material.size();
        
        int index = n - 1;
        
        while (index > 0) {
            material[index - 1] = material[index] - material[index - 1];
            material.pop_back();
            sort(material.begin(), material.end());
            index --;
        }
        
        return material[0];
    }
};