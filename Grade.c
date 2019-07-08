# SqList
//成绩表

#include <stdio.h>
#include <stdlib.h>

#define ok 		1
#define error 	0

#define LIST_INIT_SIZE 20 //表的初始长度20

typedef struct {
	long  student_ID ;
	int 	chinese;
	int 	math;
	int 	English;
	int 	histroy;
}info;
typedef info ElemType;
typedef struct {
	ElemType *base;
	int 	front;
	int 	rear;
}SqList;//顺序表 

typedef int Status ;

Status InitList(SqList &L)
{
	L.base=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(!L.base)
		return error;
	L.front=L.rear=0;
	return ok;
}
Status  EnList(SqList &L,ElemType &e)
{
	//写入数据到链表中 
		(L.base+L.rear)->student_ID=e.student_ID;
		(L.base+L.rear)->chinese=e.chinese;
		(L.base+L.rear)->math=e.math;
		(L.base+L.rear)->English=e.English;
		(L.base+L.rear)->histroy=e.histroy;
		L.rear++;
		return ok;
}
//销毁这个列表 
Status DestroyList(SqList &L)
{
	free(L.base);
	L.base=NULL;
	L.front=L.rear=0;
	return ok;
}
//遍历真个列表：
Status TravserList(SqList L)
{
		int i;
		for(i=L.front;i<L.rear;i++)
		{
				printf("学号:%d\t",(L.base+i)->student_ID);
				printf("语文:%d\t",(L.base+i)->chinese);
				printf("数学:%d\t",(L.base+i)->math);
				printf("英语:%d\t",(L.base+i)->English);
				printf("历史:%d\n",(L.base+i)->histroy);
		}
		return ok;
}
int main(void)
{
	 	SqList L;
	 	InitList(L);
	 	//学生个数:
	 	int n;
	 	printf("键入学生个数:\n");
	 	scanf_s("%d",&n,1);
	 	for(int i=0;i<n;i++)
	 	{
	 			ElemType e;
	 			printf("键入学号，语文，数学，英语，历史:\n");
	 			scanf_s("%d\t%d\t%d\t%d\t%d",&(e.student_ID),&(e.chinese),&(e.math),&(e.English),&(e.histroy));
	 			EnList(L,e);
	 	}
	 	
	 	TravserList(L);
	 	DestroyList(L);
	 	system("pause");
	 	return 0;
}
