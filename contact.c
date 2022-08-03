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
		printf("通讯录已满。\n");
	}
	else
	{
		printf("请输入成员姓名:>");
		scanf("%s", con->date[con->size].name);

		printf("请输入%s性别:>",con->date[con->size].name);
		scanf("%s", con->date[con->size].sex);
		
		printf("请输入%s年龄:>", con->date[con->size].name);
		scanf("%d", &(con->date[con->size].age));
		
		printf("请输入%s电话:>", con->date[con->size].name);
		scanf("%s", con->date[con->size].tele);
		
		printf("请输入%s住址:>", con->date[con->size].name);
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
		int i = 0;
		for (i = 0; i < con->size; i++)
		{
			printf("姓名：%s\n", con->date[i].name);
			printf("性别：%s\n", con->date[i].sex);
			printf("年龄：%d\n", con->date[i].age);
			printf("电话：%s\n", con->date[i].tele);
			printf("住址：%s\n\n", con->date[i].addr);
		}
	}
}

static int Findbyname(const C* con, char search_name[Max_name])
//该函数不仅不需要声明，还要限制作用域。
//因为.h文件中声明的函数都是我们实现通讯录功能所需要的函数，而该函数仅属于那几个函数的子函数。
//如果其他文件使用了该函数命名，也不会冲突。
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->date[i].name, search_name) == 0)
		{
			//memset(con->date[i], 0, sizeof(con->date[i]));
			return i;//找到返回下标
		}
	}
	return -1;//找不到返回-1
}

//删除规定姓名的成员信息
void DelContact(C* con)
{
	char search_name[Max_name] = "0";
	printf("请输入需要删除的成员姓名:>");
	scanf("%s", search_name);
	//寻找
	//由于查找模块和修改模块都会用到这个算法，所以我们可以将这个模块放外面公用。
	int pos = Findbyname(con, search_name);
	//删除
	if (pos == -1)
	{
		printf("通讯录中不存在该成员！\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < con->size - 1; j++)
		{
			con->date[j] = con->date[j + 1];
		}
		con->size--;
		printf("删除成功！\n");
	}
}


//查找成员
void SearchContact(const C* con)
{
	assert(con != NULL);
	printf("请选择查找的成员名:>");
	char search_name[Max_name];
	scanf("%d", search_name);
	int pos = Findbyname(con, search_name);
	if (-1 == pos)
	{
		printf("查找的成员不存在！\n");
	}
	else
	{
		printf("姓名：%s\n", con->date[pos].name);
		printf("性别：%s\n", con->date[pos].sex);
		printf("年龄：%d\n", con->date[pos].age);
		printf("电话：%s\n", con->date[pos].tele);
		printf("住址：%s\n\n", con->date[pos].addr);
	}
}


//修改成员信息
void ModifyContact(C* con)
{
	char search_name[Max_name];
	printf("请输入需要修改的成员名字:>");
	scanf("%s", search_name);
	int pos = Findbyname(con, search_name);
	if (-1 == pos)
	{
		printf("没有找到该成员！\n");
	}
	else
	{
		printf("请选择需要的修改项:>\n1.name  2.sex  3.age  4.tele  5.addr\n");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("请输入需要修改的名字:>");
			scanf("%s", con->date[pos].name);
			printf("修改完成。\n");
			break;
		case 2:
			printf("请输入需要修改的性别:>");
			scanf("%s", con->date[pos].sex);
			printf("修改完成。\n");
			break;
		case 3:
			printf("请输入需要修改的年龄:>");
			scanf("%d", &con->date[pos].age);
			printf("修改完成。\n");
			break;
		case 4:
			printf("请输入需要修改的电话:>");
			scanf("%s", con->date[pos].tele);
			printf("修改完成。\n");
			break;
		case 5:
			printf("请输入需要修改的住址:>");
			scanf("%s", con->date[pos].addr);
			printf("修改完成。\n");
			break;
		case 0:
			printf("退出修改。\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	}
}

//qsort用的回调函数
static int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//应用名字首字母排序
void SortContact(C* con)
{
	if (con->size < 1)
	{
		printf("通讯录为空，操作无意义。\n");
	}
	else
	{
		qsort((void*)con, con->size, sizeof(con->date[0].name), cmp((void*)con->date[con->size - 1].name, (void*)con->date[con->size].name));
	}
	
}