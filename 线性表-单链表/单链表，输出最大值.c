#include <stdio.h>
#include <stdlib.h>

// 定义单链表结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 定义删除单链表最大值结点并返回值的函数
int removeMaxNodeAndReturnValue(ListNode* head) {
    if (head == NULL) {
        return -1; // 链表为空
    }

    ListNode* maxNode = head;
    ListNode* prevMaxNode = NULL;

    while (maxNode != NULL) {
        if (maxNode->next != NULL && maxNode->next->val > maxNode->val) {
            prevMaxNode = maxNode;
            maxNode = maxNode->next;
        } else {
            // 删除最大值结点
            if (prevMaxNode == NULL) {
                head = maxNode->next;
            } else {
                prevMaxNode->next = maxNode->next;
            }

            int maxVal = maxNode->val;
            free(maxNode);
            return maxVal;
        }
    }

    return -1; // 链表中没有最大值结点
}

// 定义打印单链表函数
void printList(ListNode* head) {
    ListNode* node = head;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\\n");
}

int main() {
    // 创建单链表 1->3->5->7->9
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 1;
    ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
    node2->val = 3;
    head->next = node2;
    ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
    node3->val = 5;
    node2->next = node3;
    ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
    node4->val = 7;
    node3->next = node4;
    ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));
    node5->val = 9;
    node4->next = node5;

    // 打印原始链表
    printf("原始链表: ");
    printList(head);

    int maxVal = removeMaxNodeAndReturnValue(head);

    // 打印删除最大值结点后的链表
    printf("删除最大值结点后的链表: ");
    printList(head);

    printf("最大值结点的值为: %d\\n", maxVal);

    free(head);

    return 0;
}
