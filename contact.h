#pragma once
//contact.h 写入通讯录引用的头文件和函数声明

#include <stdio.h>
#include <string.h>


#define Max 1000


#define Max_name 20
#define Max_sex 5
#define Max_tele 12
#define Max_addr 40

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
	P date[Max];
	//嵌套使用上面创建的结构体，来创建出来程序所需要的结构体数组。
	int size;
}C;

//函数声明
void InitContact(C* con);
void AddContact(C* con);
void ShowContact(const C* con);