/*
* @Author: sphao
* @Date:   2018-05-22 16:21:09
* @Last Modified by:   sphao
* @Last Modified time: 2018-05-23 17:15:50
*/
#include <cstdio>
#include <cstdlib>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList CreatListH(LinkList L);	//头插法创建链表
LinkList CreatListT(LinkList L);	//尾插法创建链表
void TravelList(LinkList L);		//遍历链表
LNode* GetElem(LinkList L, int i);	//按序号查找链表结点
LNode* LocateElem(LinkList L, ElemType e);	//按值查找链表结点

int main(int argc, char const *argv[])
{
	LinkList L = CreatListT(L);
	//创建链表L H为头插法，L为尾插法
	TravelList(L);
	//遍历链表
	printf("%d\n", GetElem(L,3)->data);
	return 0;
}

LinkList CreatListH(LinkList L)		//头插法创建链表
{
	LNode *s; ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while(x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}		
	return L;
}

LinkList CreatListT(LinkList L)		//尾插法创建链表
{
	LNode *s, *r;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	L->next = NULL;
	scanf("%d", &x);
	while(x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		r->next = s;
		s->data = x;
		s->next = NULL;
		r = r->next;
		scanf("%d", &x);
	}
	return L;
}

void TravelList(LinkList L)			//遍历链表
{
	LNode *P = L->next;
	while(P != NULL)
	{
		printf("%d", P->data);
		if(P->next != NULL)
			printf(" ");
		else printf("\n");
		P = P->next;
	}
}

LNode* GetElem(LinkList L, int i)	//按序号查找值
{
	int j = 1;
	LNode *p = L->next;
	if(i == 0)
		return L;
	if(i < 1)
		return NULL;
	while(p && j < i)
	{
		p = p->next;
		j ++;
	}
	return p;
}
