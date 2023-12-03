class Solution {
public:
    string entityParser(string text) {
        // 初始化转换规则
        std::unordered_map<string, string> transfor {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };

        int n = text.size();

        string res("");
        
        for (int i = 0; i < n; ) {
            if (text[i] == '&') {
                int j = i + 1;

                while (j < n && j - i < 6 && text[j] != ';') j ++;

                string tem = text.substr(i, std::fmin(j + 1, n) - i);

                if (transfor.find(tem) != transfor.end()) {
                    res += transfor[tem];

                    i = j + 1;

                    continue;
                }
            }

            res += text[i ++];
        }

        return res;
    }
};