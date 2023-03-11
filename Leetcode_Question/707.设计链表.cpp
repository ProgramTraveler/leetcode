/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start

/* class MyLinkedList {
public:
    //定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {} 
    };
    MyLinkedList() {
        dummyHead = new LinkedNode(0); //虚拟头节点
        size = 0;
    }
    
    int get(int index) {
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = dummyHead -> next;
        while (index --) {
        cur = cur -> next;
        }
        return cur -> val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode -> next = dummyHead -> next;
        dummyHead -> next = newNode;
        size ++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead;
        while (cur -> next != nullptr) {
            cur = cur -> next;
        }
        cur -> next = newNode;
        size ++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead;
        while (index --) {
            cur = cur -> next;
        }
        newNode -> next = cur -> next;
        cur -> next = newNode;
        size ++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return ;
        LinkedNode* cur = dummyHead;
        while (index --) {
            cur = cur -> next;
        }
        LinkedNode*  temp = cur -> next;
        cur -> next = cur -> next -> next;
        delete temp;
        size --;
    }
private :
    LinkedNode* dummyHead;
    int size;
}; */

class MyLinkedList { //主要是 index 和 size 的对应
private:
    int size;
    ListNode *head;

public:
    MyLinkedList() {
        this -> size = 0;
        this -> head = new ListNode(0); //设计一个头节点
    }
    
    int get(int index) {
        cout << index << " " << size << endl;
        if (index >= size || index < 0) return -1; //索引无效的话返回-1
        
        ListNode* temp = head; //临时节点

        for (int i = 0; i <= index; i ++)  temp = temp -> next;

        return temp -> val;
    }
    
    void addAtHead(int val) {
       addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return; //不满足要求返回空

        index = max (0, index); //防止输入的负数

        ListNode* node = new ListNode(val);

        ListNode* temp_l = head;

        for (int i = 0; i < index; i ++) temp_l = temp_l -> next;

        node -> next = temp_l -> next;
        temp_l -> next = node;

        size ++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        ListNode* temp_l = head;

        for (int i = 0; i < index; i ++) temp_l = temp_l -> next;

        ListNode* p = temp_l -> next;

        temp_l -> next = temp_l -> next -> next;
        delete p;

        size --;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

