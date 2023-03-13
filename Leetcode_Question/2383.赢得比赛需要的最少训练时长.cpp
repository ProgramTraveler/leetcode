class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // 精力和经验都需要严格超过对手
        // 两个数组长度的大小是相同的
        int res = 0, n = energy.size();

        int idx = 0;

        bool en, ex = false;

        while (idx < n) {
        
            if (initialEnergy <= energy[idx]) {
                res += ((energy[idx] - initialEnergy) + 1);

                initialEnergy += ((energy[idx] - initialEnergy) + 1);

                en = false;

            } else {
                initialEnergy -= energy[idx];

                en = true;
            }

            idx += en ? 1 : 0;
        }

        idx = 0;

        while  (idx < n) {
             if (initialExperience <= experience[idx]) {
                res += ((experience[idx] - initialExperience) + 1);

                initialExperience += ((experience[idx] - initialExperience) + 1);

                ex = false;
            } else {
                initialExperience += experience[idx];

                ex = true;
            }

            idx += ex ? 1 : 0;
        }

        return res;
    }
};