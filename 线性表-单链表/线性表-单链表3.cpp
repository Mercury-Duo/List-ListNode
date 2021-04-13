#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_DEPRECATE 1
//#include<iostream>
struct Data {
	char name[5];//����
	int number;//ͼ��
	int quantity;//����
	char material[10];//����
};
struct Node {
	struct Data data;
	struct Node* next;
};
struct Node* CreatList();//������ͷ
struct Node* CreatNode(struct Data data);//�����ڵ�
void insertList(struct Node* headnode, int data);//����ڵ�
void printlist(struct Node* headnode);//��ӡ�ڵ�
void deletelist(struct Node* headnode, int local);//ɾ���ڵ�
struct Node* reverlist(struct Node*& headnode);//��������
struct Node* CreatList() {
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));
	headnode->next = NULL;
	return headnode;
}
struct Node* CreatNode(struct Data data) {
	struct Node* Node1 = (struct Node*)malloc(sizeof(struct Node));
	Node1->data = data;
	Node1->next = NULL;
	return Node1;
}
void insertList(struct Node* headnode, struct Data data) {
	struct Node* newNode = CreatNode(data);
	newNode->next = headnode->next;
	headnode->next = newNode;
}
void printlist(struct Node* headnode) {
	struct Node* pointNode = headnode->next;
	printf("����\t���\t����\t����\n");
	while (pointNode) {
		printf("%s\t%d\t%d\t%s", pointNode->data.name, pointNode->data.number, pointNode->data.quantity, pointNode->data.material);
		printf("\n");
		pointNode = pointNode->next;
	}
}
void deletelist(struct Node* headnode, int local)
{
	int i = 1;
	struct Node* Node1 = headnode->next;
	struct Node* Node1front = headnode;
	for (i = 1; i < local; i++)
	{
		Node1front = Node1;
		Node1 = Node1front->next;
	}
	Node1front->next = Node1->next;
	free(Node1);
}
struct Node* reverlist(struct Node*& headnode)
{
	struct Node* q;
	struct Node* p = headnode->next;
	headnode->next = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		q->next = headnode->next;
		headnode->next = q;
	}
	return 0;
}
int main(void) {
	struct Data data;int n, m, x, y;
	struct Node* p;
	struct Node* L = CreatList();
	printf("�������ݵĸ���");
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		printf("�������%d������(�м��ÿո����)", i);
		scanf("%s%d%d%s", data.name, &data.number, &data.quantity, data.material);
		insertList(L, data);
	}
	reverlist(L);
	printlist(L);
	printf("ɾ����1���밴2");
	scanf("%d", &m);
	if (m == 1) {
		printf("������Ҫɾ���ڼ�������");
		scanf("%d", &x);
		deletelist(L, x);
		printlist(L);
		printf("ɾ���ɹ�");
	}
	if (m == 2) {
		printf("������Ҫ���ĵڼ�������");
		scanf("%d", &y);
		p = L->next;
		for (int j = 1;j < y;j++) {
			p = p->next;
		}
		printf("������Ҫ���ĵ�����");
		scanf("%s%d%d%s", p->data.name, &p->data.number, &p->data.quantity, p->data.material);
		printlist(L);
		printf("���ĳɹ�");
	}
}