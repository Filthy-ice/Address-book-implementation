#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//contact.c实现通讯录算法
//重置结构体数组
void InitContact(C* con)
{
	memset(con->date, 0, sizeof(con->date));//创建的变量结构里面全置0
	con->size = 0;//表示这个变量里最初只有0个成员。
}

//添加成员数据
void AddContact(C* con)
{
	if (con->size == Max)
	{
		pirntf("通讯录已满。\n");
	}
	else
	{
		printf("请输入成员姓名:>\n");
		scanf("%s", con->date[con->size].name);

		printf("请输入%s性别:>\n",con->date[con->size].sex);
		scanf("%s", con->date[con->size].sex);
		
		printf("请输入%s年龄:>\n", con->date[con->size].name);
		scanf("%d", &(con->date[con->size].age));
		
		printf("请输入%s电话:>\n", con->date[con->size].name);
		scanf("%s", con->date[con->size].tele);
		
		printf("请输入%s住址:>\n", con->date[con->size].name);
		scanf("%s", con->date[con->size].addr);

		con->size++;
		printf("添加成功！\n");
	}
}

//输入完成只显示添加成功，所以我们要打印一下。
void ShowContact(const C* con)
{
	if (con->size == 0)
	{
		printf("通讯录为空！\n");
	}
	else
	{
		printf("姓名：%s\n", con->date[con->size].name);
		printf("性别：%s\n", con->date[con->size].sex);
		printf("年龄：%d\n", con->date[con->size].age);
		printf("电话：%s\n", con->date[con->size].tele);
		printf("住址：%s\n", con->date[con->size].addr);
	}
}