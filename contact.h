#pragma once
//contact.h д��ͨѶ¼���õ�ͷ�ļ��ͺ�������

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <search.h>

//#define Max 1000  //��Ϊ��̬���٣���ô�����û���ˡ�
//��ʼ��д
#define DEFAULT_sz 3

#define Max_name 20
#define Max_sex 5
#define Max_tele 12
#define Max_addr 40

//�˵�
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

//������Ա����
typedef struct PeoInfo
{
	char name[Max_name];
	char sex[Max_sex];
	int age;
	char tele[Max_tele];
	char addr[Max_addr];
}P;

//ͨѶ¼����
typedef struct Contact
{
	P* date;//ԭջ���������飬��ʹ�õ�ַ�������п��ٶ�̬�ڴ档
	//Ƕ��ʹ�����洴���Ľṹ�壬������������������Ҫ�Ľṹ�����顣
	int size;//ԭ���Ԫ�������ֱ�ʾ��������Ԫ�ء�
	int capacity;//��ʾ�������Ԫ�ء�
}C;

//��������
//����
void InitContact(C* con);
//���
void AddContact(C* con);
//չʾ
void ShowContact(const C* con);
//ɾ��
void DelContact(C* con);
//����
void SearchContact(const C* con);
//�޸�
void ModifyContact(C* con);
//���򣬰�����������ĸ
void SortContact(C* con);

//�˳����ͷŶ�̬�ڴ档
void DestroyContact(C* con);
