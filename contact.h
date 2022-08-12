#pragma once
//contact.h 写入通讯录引用的头文件和函数声明

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <search.h>

//#define Max 1000  //改为动态开辟，那么这个就没用了。
//开始改写
#define DEFAULT_sz 3

#define Max_name 20
#define Max_sex 5
#define Max_tele 12
#define Max_addr 40

//菜单
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//单个成员类型
typedef struct PeoInfo
{
	char name[Max_name];
	char sex[Max_sex];
	int age;
	char tele[Max_tele];
	char addr[Max_addr];
}P;

//通讯录类型
typedef struct Contact
{
	P* date;//原栈区开辟数组，现使用地址，代码中开辟动态内存。
	//嵌套使用上面创建的结构体，来创建出来程序所需要的结构体数组。
	int size;//原最大元素量，现表示数组现有元素。
	int capacity;//表示数组最大元素。
}C;

//函数声明
//重置
void InitContact(C* con);
//添加
void AddContact(C* con);
//展示
void ShowContact(const C* con);
//删除
void DelContact(C* con);
//搜索
void SearchContact(const C* con);
//修改
void ModifyContact(C* con);
//排序，按照名字首字母
void SortContact(C* con);

//退出，释放动态内存。
void DestroyContact(C* con);
