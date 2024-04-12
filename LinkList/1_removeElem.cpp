// https://leetcode.cn/problems/remove-linked-list-elements/
/*
203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]

提示：
列表中的节点数目在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= val <= 50
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    { // 不带头节点
        // 处理前面重复的(如果有的话)
        while (head != nullptr && head->val == val)
        {
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode *cur = head;
        while (cur->next != NULL && cur != NULL)
        {
            if (cur->next->val == val)
            {
                auto tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }

        return head;
    }
    ListNode *func(ListNode *head, int val)
    { // 虚拟源节点方法
        ListNode *dummy = new ListNode;
        dummy->next = head;
        auto cur = dummy;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                auto tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
int main(int argc, char const *argv[])
{
    // 阿米诺斯 链表的main测试例不好写啊
    ListNode n1(1);
    ListNode n2(2, &n1);
    ListNode n3(2, &n2);
    ListNode n4(3, &n3);
    Solution instance;
    auto res = instance.removeElements(&n4, 2);

    return 0;
}
