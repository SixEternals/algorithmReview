// https://leetcode.cn/problems/design-linked-list/description/
/*
707. 设计链表
你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：
MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。


示例：
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]
解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3

提示：
0 <= index, val <= 1000
请不要使用内置的 LinkedList 库。
调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
*/
#include <iostream>
using namespace std;
class MyLinkedList
{
    MyLinkedList *next, *head = nullptr, *tail = nullptr; //
    int len = 0;
    int var;

public:
    MyLinkedList *next, *head = nullptr, *tail = nullptr; //
    int len = 0;
    int var;
    MyLinkedList() : next(nullptr), var(0) {}
    MyLinkedList(int var) : next(nullptr), var(var) {}
    int get(int index)
    {
        if (index < 0 || index >= len)
            return -1;
        return 0;
    }

    void addAtHead(int val)
    {
        MyLinkedList *newHead = new MyLinkedList(val);
        if (head == nullptr)
        {
            head = newHead;
            tail = head;
            len++;
            return;
        }
        newHead->next = head;
        head = newHead;
        len++;
    }

    void addAtTail(int val)
    {
        MyLinkedList *dummy = new MyLinkedList();
        MyLinkedList *newNode = new MyLinkedList(val);
        len++;
        // 如果先前找到过tail的话
        if (tail != nullptr)
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }

        dummy->next = head;
        MyLinkedList *cur = dummy;
        while (cur != nullptr && cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        tail = newNode;
        delete dummy;
    }

    void addAtIndex(int index, int val)
    { // 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
        // index = len 加到末尾 lndex > len 不加
        if (index < 0 || index > len)
            return;
        if (tail != nullptr && index == len)
        {
            MyLinkedList *newNode = new MyLinkedList(val);
            tail->next = newNode;
            tail = newNode;
        }
        // 如果一次addAtTail都没有执行过的话 而且下标合法且不为最后一个
        // 如果index为0
        if (index == 0)
        {
            MyLinkedList *newNode = new MyLinkedList(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        // 正常情况
        int cnt = 0;
        MyLinkedList *cur = head;
        while (cnt < index - 1)
        {
            cnt++;
            cur = cur->next;
        }
        MyLinkedList *newNode = new MyLinkedList(val);
        newNode = cur->next;
        cur->next = newNode;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;
        // 如果删最后一个
        if (index == len - 1)
        {
        }
        MyLinkedList *dummy = new MyLinkedList();
        dummy->next = head;
        MyLinkedList *cur = dummy;
        int curindex = 0;
        while (curindex < index - 1)
        {
            cur = cur->next;
            curindex++;
        }
        cur->next = cur->next->next;
        delete dummy;
    }
};
int main(int argc, char const *argv[])
{
    MyLinkedList *obj = new MyLinkedList();
    int index = 1; //
    auto val = 2;  //
    int param_1 = obj->get(index);
    obj->addAtHead(val);         // 2
    obj->addAtHead(3);           // 3 2
    obj->addAtHead(4);           // 4 3 2
    obj->addAtTail(5);           // 4 3 2 5
    obj->addAtIndex(index, val); //
    obj->deleteAtIndex(index);
    return 0;
}
/*

*/