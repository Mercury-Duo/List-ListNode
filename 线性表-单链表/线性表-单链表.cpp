#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
//建立头节点
struct Node* CreatNode() {
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));
	headnode->data = 0;
	headnode->next = NULL;
	return headnode;
}
//建立新节点
struct Node* CreatList(int data) {
	struct Node* ListLink = (struct Node*)malloc(sizeof(struct Node));
	ListLink->data = data;
	ListLink->next = NULL;
	return ListLink;
}
//插入节点
void insertList(struct Node* headnode, int data)
{
	struct Node* newnode = CreatList(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
}
//打印节点
void printlist(struct Node* headnode) {
	struct Node* pointlist = headnode->next;
	while (pointlist) {
		printf("%d", pointlist->data);
		printf("\n");
		pointlist = pointlist->next;
	}
}
void deletenode(struct Node* headnode, int x) {
	struct Node* posnode = headnode->next;
	struct Node* posnodefront = headnode;
	if (posnode->data == NULL) {
		printf("链表为空，无法删除");

	}
	else
	{
		while (posnode->data != x) {
			posnodefront = posnode;
			posnode = posnodefront->next;
			if (posnode == NULL) { printf("未找到指定位置，无法删除"); return; }
		}
		posnodefront->next = posnode->next;
		free(posnode);
	}
}
int main() {
	int n, k, y;
	printf("请输入建立节点个数");
	scanf_s("%d", &n);
	struct Node* L = CreatNode();
	for (int i = 1;i <= n;i++) {
		printf("请输入第%d个数据", i);
		scanf_s("%d", &k);
		insertList(L, k);
	}
	printlist(L);
	printf("输入删除的元素");
	scanf_s("%d", &y);
	deletenode(L, y);
	printlist(L);
}
