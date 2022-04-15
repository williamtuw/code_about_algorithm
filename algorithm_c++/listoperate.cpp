//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node
//{
//	int num;
//	Node* next = NULL;
//};
//void create(Node* head)
//{
//	int n;
//	scanf_s("%d", &n);
//	Node* node,*temp = head;
//	for (int i = 0; i < n; i++)
//	{
//		node = new Node();
//		scanf_s("%d", &node->num);
//		temp->next = node;
//		temp = node;
//	} 
//}
//Node* insert(Node* head, Node* node, int n)
//{
//	int count = 0;
//	Node* temp;
//	while (head)
//	{
//		if (count == n)
//		{
//			temp = head->next;
//			head->next = node;
//			node->next = temp;
//			break;
//		}
//		head = head->next;
//		count++;
//	}
//	return head;
//}
//bool del(Node* head, int n)
//{
//	int count = 0;
//	Node* temp;
//	while (head)
//	{
//		if (count == n)
//		{
//			temp = head->next;
//			head->next = temp->next;
//			delete temp;
//			return true;
//		}
//		head = head->next;
//		count++;
//	}
//	return false;
//}
//void print(Node* head)
//{
//	head = head->next;
//	while (head)
//	{
//		printf("%d", head->num);
//		if (head->next != NULL)printf(" ");
//		head = head->next;
//	}
//}
//int main_fmatrix()
//{
//	Node* head = new Node();
//	int m,index;
//	create(head);
//	scanf_s("%d", &m);
//	for (int i = 0; i < m; i++)
//	{
//		scanf_s("%d", &index);
//		del(head, index-1);
//	}
//	print(head);
//
//	return 0;
//}
//
