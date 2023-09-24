/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DLinkedNode {
    int key, value;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
// 逐出最久未使用的关键字
// 队列？
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();

        head -> next = tail;
        tail -> pre = head;
    }
    
    int get(int key) { // 这里需要更新 使用关键字的时间
        if (!cache.count(key)) return -1;

        // key 存在 通过 hash 表定位 再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);

        return node -> value;

    }
    
    void put(int key, int value) {
        if (!cache[key]) {
            // 如果 key 不存在 创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进 hash 表
            cache[key] = node;
            // 添加到双向链表头部
            addToHead(node);
            size ++;

            if (size > capacity) { // 超出容量 删除双向链表的尾部节点
                DLinkedNode* remove = removeTail();

                // 删除 hash 表中的对应项
                cache.erase(remove -> key);

                // 防止内存泄漏
                delete remove;

                size --;
            }
        } else { // 如果 key 存在 通过 hash 表定位 再修改 value 并移到头部
            DLinkedNode* node = cache[key];

            node -> value = value;

            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node -> pre = head;
        node -> next = head -> next;

        head -> next -> pre = node;
        head -> next = node;
    }

    void removeNode(DLinkedNode* node) {
        node -> next -> pre = node -> pre;
        node -> pre -> next = node -> next;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail -> pre;

        removeNode(node);
        return node;
    }

private:
    unordered_map<int, DLinkedNode*> cache;

    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

