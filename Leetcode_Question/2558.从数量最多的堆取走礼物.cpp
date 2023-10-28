class Solution {
public:
    using ll = long long;
    long long pickGifts(vector<int>& gifts, int k) {
        // 最大堆
        priority_queue<ll> heap(gifts.begin(), gifts.end()); // ! 最大堆的写法要记住

        ll res = 0;

        while (k --) {
            ll cnt = heap.top();
            heap.pop();

            heap.push((int)sqrt(cnt));
        }

        while (heap.size()) {
            res += heap.top();
            heap.pop();
        }

        return res;
    }
};